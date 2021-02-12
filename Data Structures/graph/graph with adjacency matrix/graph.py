




from typing import Any


class Vertice(object):

    def __init__(self, tag: Any) -> None:
        self.__tag = tag
        self.__fields = {}


    def add_field(self, **fields) -> None:
        for key in fields.keys():
            self.__fields[key] = fields[key]


    def tag(self) -> Any:
        return self.__tag





class Graph(object):

    def __init__(self, number_of_V: int) -> None:
        self.number_of_V = number_of_V
        self.number_of_E = 0
        self.adj = [[-1 for _ in range(number_of_V)] for _ in range(number_of_V)]








if __name__ == "__main__":
    pass
