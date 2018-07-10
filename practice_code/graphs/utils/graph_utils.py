class GraphNode(object):
    def __init__(self, key, val=None):
        self._key = key
        self._val = val

    @property
    def key(self):
        return self._key

    @property
    def val(self):
        return self._val

    def __hash__(self):
        return hash(self._key)

    def __str__(self):
        return "".join(["(", self._key, ",", self._val, ")"])

class Edge(object):
    def __init__(self, from_vertex=None, to_vertex=None, is_directed=False):
        self._is_directed = is_directed
        self._from_vertex = from_vertex
        self._to_vertex = to_vertex

    @property
    def from_vertex(self):
        return self._from_vertex

    @property
    def to_vertex(self):
        return self._to_vertex

    @property
    def directed(self):
        return self._is_directed

    def __str__(self):
        return "".join(["(", self._from_vertex, ",", self._to_vertex, ")"])

class Graph(object):
    def __init__(self, edges):
        self._vertices = {}
        # Map of vertex key to list of vertex nodes.
        self._adjacency_list = {}
        """
        List of Edge objects.
        """
        for edge in edges:
            from_vertex = GraphNode(edge.from_vertex)
            to_vertex = GraphNode(edge.to_vertex)
            if not self._vertices.has_key(from_vertex.key):
                self._vertices[from_vertex.key] = from_vertex
            if not self._vertices.has_key(to_vertex.key):
                self._vertices[to_vertex.key] = to_vertex
            # Add to adjacency list.
            self._adjacency_list.setdefault(from_vertex.key,
                []).append(to_vertex)
            # For a undirected edge, add the vertex to the adjancency list.
            if not edge.directed:
                self._adjacency_list.setdefault(to_vertex.key, []).append(
                    from_vertex)

    def vertices(self):
        """
        Returns:
            {str: GraphNode}
        """
        nodes = []
        for key, value in self._vertices.iteritems():
            nodes.append(value)
        return nodes

    def neighbors(self, source_vertex):
        """
        source_vertex(str): source vertex key.
        Returns:
            [GraphNode]
        """
        if self._adjacency_list.has_key(source_vertex):
            return self._adjacency_list[source_vertex]
        else:
            return []

    def print_vertices(self):
        """
        Util function to print vertices.
        """
        for vertex in self._vertices:
            print "vertex: {0}\n".format(vertex)

    def print_edges(self):
        """
        Util function to print edges.
        """
        for vertex, neighbors in self._adjacency_list.iteritems():
            for neighbor in neighbors:
                edge = Edge(from_vertex=vertex,
                            to_vertex=neighbor.key)
                print "Edge: ", edge

    def dfs_basic(self, source_vertex):
        """
        Util function to traverse the graph using Depth First
        Search.
        """
        print "DFS:\n"
        self._visited = {}
        self._dfs_internal(source_vertex)

    def _dfs_internal(self, source_vertex):
        self._visited[source_vertex] = True
        print source_vertex, "\n"
        for neighbor in self.neighbors(source_vertex):
            if neighbor.key not in self._visited:
                self._dfs_internal(neighbor.key)
