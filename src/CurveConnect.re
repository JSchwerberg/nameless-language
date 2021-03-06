let f = (sourcePosition: Point.t, sinkPosition: Point.t, nudge: float): string => {
  let delta =
    Point.{
      x: sinkPosition.x -. sourcePosition.x,
      y: sinkPosition.y -. sourcePosition.y,
    };
  let radius = 15.0;
  let direction =
    Point.{x: delta.x < 0.0 ? (-1.0) : 1.0, y: delta.y < 0.0 ? (-1.0) : 1.0};
  let goesUpward = direction.x < 0.0;
  let leftIsDownward = direction.y < 0.0 ? goesUpward : !goesUpward;
  let curveSize =
    Point.{
      x: min(abs_float(delta.x) /. 2.0, radius),
      y: min(abs_float(delta.y) /. 2.0, radius),
    };
  Printf.sprintf(
    "h %f a %f,%f 0 0,%i %f,%f v %f a %f,%f 0 0,%i %f,%f h %f",
    delta.x /. 2.0 -. curveSize.x *. direction.x +. nudge,
    curveSize.x,
    curveSize.y,
    leftIsDownward ? 1 : 0,
    curveSize.x *. direction.x,
    curveSize.y *. direction.y,
    delta.y -. curveSize.y *. 2.0 *. direction.y,
    curveSize.x,
    curveSize.y,
    leftIsDownward ? 0 : 1,
    curveSize.x *. direction.x,
    curveSize.y *. direction.y,
    delta.x /. 2.0 -. curveSize.x *. direction.x -. nudge,
  );
};
