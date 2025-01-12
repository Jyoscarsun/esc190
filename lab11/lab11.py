class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = []

def are_nodes_linked(node1, node2):
    # node1 and node2 are linked if there is an edge between
    # node1 and node2
    # Assume graph is undirected
    return node2 in node1.neighbours  # don't need to check that node1 is in node2.neighbours


def get_node_by_int(nodes, node_int):
    for node in nodes:
        if node.value == node_int:
            return node
    # for node in nodes:
    #     if node.value == node_str:
    #         return node
    # return None

def are_nodeint_linked(nodes, node1_int, node2_int):
    node1 = get_node_by_int(nodes, node1_int)
    node2 = get_node_by_int(nodes, node2_int)
    if node1 is None or node2 is None:
        return False
    return are_nodes_linked(node1, node2)

def BFS(nodes):
    traversal = []
    not_visited = []
    count = 0
    for node in nodes:
        not_visited.append(node.value)
        count += 1
    while len(traversal) < count:
        DS = []
        DS.append(not_visited[0])
        not_visited.pop(0)
        traversal.append(DS[0])
        while DS:
            if DS[0] in not_visited:
                not_visited.remove(DS[0])
                traversal.append(DS[0]) 
            for neighbour in get_node_by_int(nodes, DS[0]).neighbours:
                if neighbour.value in not_visited:
                    DS.append(neighbour.value)
            DS.pop(0)
    return traversal

def DFS(nodes):
    traversal = []
    not_visited = []
    count = 0
    for node in nodes:
        not_visited.append(node.value)
        count += 1
    while len(traversal) < count:
        DS = []
        DS.append(not_visited[0])
        not_visited.pop(0)
        traversal.append(DS[0])
        while DS:
            popped = DS.pop(len(DS)-1)
            if popped in not_visited:
                not_visited.remove(popped)
                traversal.append(popped) 
            for neighbour in get_node_by_int(nodes, popped).neighbours:
                if neighbour.value in not_visited:
                    DS.append(neighbour.value)
    return traversal

def make_node_graph():
    node1 = Node(1)
    node2 = Node(2)
    node3 = Node(3)
    node4 = Node(4)
    node5 = Node(5)
    node6 = Node(6)

    node1.neighbours = [node3, node6]
    node2.neighbours = [node3, node5]
    node3.neighbours = [node1, node2, node4]
    node4.neighbours = [node3, node5]
    node5.neighbours = [node2, node3, node4, node6]
    node6.neighbours = [node1, node5]

    return [node1, node2, node3, node4, node5, node6]

    # node_dict = {}
    # for node in [node1, node2, node3, node4, node5, node6]:
    #     node_dict[node.value] = node
    
    # return node_dict

if __name__ == '__main__':
    nodes = make_node_graph()
    traversal_BFS = BFS(nodes)
    traversal_DFS = DFS(nodes)
    print(traversal_BFS)
    print(traversal_DFS)