




class Vertice(object):

    def __init__(self, tag) -> None:
        self.__tag = tag
        self.__fields = {}


    def add_field(self, **fields):
        for key in fields.keys():
            self.__fields[key] = fields[key]





class Graph(object):

    def __init__(self, number_of_V: int) -> None:
        self.number_of_V = number_of_V
        self.number_of_E = 0
        self.adj = [[-1 for _ in range(number_of_V)] for _ in range(number_of_V)]








if __name__ == "__main__":
    pass
