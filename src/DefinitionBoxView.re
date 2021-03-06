[@react.component]
let make =
    (
      ~name: string,
      ~position: Point.t,
      ~size: Point.t,
      ~nodeWidth: float,
      ~textHeight: float,
      ~selected: bool=false,
      ~onClick=?,
      ~onDoubleClick=?,
      ~onMouseDown=?,
      ~onTouchStart=?,
      ~onMouseUp=?,
      ~onTouchEnd=?,
    ) => {
  <g ?onDoubleClick ?onClick ?onMouseDown ?onMouseUp ?onTouchStart ?onTouchEnd>
    <rect
      x={FloatToPixels.f(position.x +. nodeWidth)}
      y={FloatToPixels.f(position.y +. textHeight)}
      width={FloatToPixels.f(size.x -. nodeWidth *. 2.0)}
      height={FloatToPixels.f(size.y -. textHeight)}
      fill={selected ? "blue" : "black"}
      fillOpacity="0.05"
    />
    <NibsBoxView
      position={x: position.x, y: position.y +. textHeight}
      height={size.y -. textHeight}
      nodeWidth
      textHeight
      selected
    />
    <NibsBoxView
      position={
        x: position.x +. size.x -. nodeWidth,
        y: position.y +. textHeight,
      }
      height={size.y -. textHeight}
      nodeWidth
      textHeight
      selected
    />
    <rect
      x={FloatToPixels.f(position.x)}
      y={FloatToPixels.f(position.y)}
      width={FloatToPixels.f(size.x)}
      height={FloatToPixels.f(textHeight)}
      fill={selected ? "blue" : "black"}
      fillOpacity="0.1"
    />
    <text
      textAnchor="middle"
      alignmentBaseline="central"
      x={FloatToPixels.f(position.x +. size.x /. 2.0)}
      y={FloatToPixels.f(position.y +. textHeight /. 2.0)}>
      {ReasonReact.string(name)}
    </text>
  </g>;
};
