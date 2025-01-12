import numpy as np

class Node:
    def __init__(self, value):
        self.value = value
        self.neighbours = LinkedList()

class LinkedListNode:
    def __init__(self, value):
        self.value = value
        self.next = None

class LinkedList:
    def __init__(self):
        self.head = None
    
    def add(self, value):
        new_node = LinkedListNode(value)
        if not self.head:
            self.head = new_node
        else:
            current = self.head
            while current.next:
                current = current.next
            current.next = new_node
    
    def __iter__(self):
        current = self.head
        yield current.value
        current = current.next
    
def are_nodes_linked(node1, node2):
    return node2.value in node1.neighbours

def get_node_by_str(nodes, node_str):
    return nodes.get(node_str, None)

def are_airports_linked(airports, airport1, airport2):
    airport1 = get_node_by_str(airports, airport1)
    airport2 = get_node_by_str(airports, airport2)
    if airport1 is None or airport2 is None:
        return False
    return are_nodes_linked(airport1, airport2)

def convert_to_adj_matrix(airports):
    num_airports = len(airports) # Obtain the length of the airport dictionary
    adj_matrix = np.zeros((num_airports, num_airports), dtype=int) # Create the adjacency matrix with integer zeros
    airport_callsigns = sorted(list(airports.keys()))
    airport_callsigns_idx = {airport_callsign: i for i, airport_callsign in enumerate(airport_callsigns)}

    for airport_callsign, airport in airports.items():
        for neighbour_node in airport.neighbours:
            neighbour_callsign = neighbour_node.value
            adj_matrix[airport_callsigns_idx[airport_callsign], airport_callsigns_idx[neighbour_callsign]] = 1

    return adj_matrix, airport_callsigns_idx

def make_airport_graph1():
    # Nodes for graph making
    yyz = Node("YYZ")
    yvr = Node("YVR")
    yul = Node("YUL")
    whitehorse = Node("Whitehorse")

    # Access the neighbours list for the nodes and add airports
    yyz.neighbours.add(yvr)
    yyz.neighbours.add(yul)
    yvr.neighbours.add(yyz)
    yvr.neighbours.add(yul)
    yvr.neighbours.add(whitehorse)
    yul.neighbours.add(yyz)
    yul.neighbours.add(yvr)
    whitehorse.neighbours.add(yvr)

    airport_dict = {}
    for airport in [yyz, yvr, yul, whitehorse]:
        airport_dict[airport.value] = airport

    return airport_dict

if __name__ == "__main__":
    airports = make_airport_graph1()
    print("Toronto (YYZ) is connected to Montreal (YUL)?", are_airports_linked(airports, "YYZ", "YUL"))