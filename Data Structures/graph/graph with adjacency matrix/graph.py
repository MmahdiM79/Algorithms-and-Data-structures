


class Graph(object):

    def __init__(self, number_of_V: int) -> None:
        self.__number_of_V = number_of_V
        self.__number_of_E = 0
        self.__Es = {}
        self.__adj = [[-1 for _ in range(number_of_V)] for _ in range(number_of_V)]



    def add_edge(self, u: int, v: int, weight: float) -> None:
        if u >= self.__number_of_V or u < 0:
            raise Exception("wrong index for vertice u")
        if v >= self.__number_of_V or v < 0:
            raise Exception("wrong index for vertice v")

        self.__adj[u][v] = weight
        self.__number_of_E += 1
        self.__Es[(u, v)] = weight
        




if __name__ == "__main__":
    pass
