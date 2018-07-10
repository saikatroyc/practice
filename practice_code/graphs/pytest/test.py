from graphs.utils.graph_utils import GraphNode, Edge, Graph

e1 = Edge('A', 'B')
e2 = Edge('B', 'C')
e3 = Edge('C', 'D')
e4 = Edge('D', 'A')

g = Graph([e1, e2, e3, e4])
g.print_vertices()
g.print_edges()

g.dfs_basic('B')
