let f =
    (nodes: NodeMap.t, connections: ConnectionMap.t)
    : list(list(NodeWithID.t)) =>
  TopologicallySortNodes.f(
    Belt.List.map(Belt.Map.String.toList(nodes), ((nodeID, node)) =>
      NodeWithID.{id: nodeID, node}
    ),
    connections,
    Belt.Set.fromArray(
      [|NodeScope.GraphScope|],
      ~id=(module NodeScopeComparable.C),
    ),
  );
