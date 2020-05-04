import numpy
from ctypes import cdll

class Vector:
    def __init__(self,data):
        if(data.ndim == 1):
            self.data = data
            self.row = data.shape[0]
        else:
            print("error")

    def __add__(self, other):
        temp = numpy.zeros_like(self.data)
        if(self.row == other.row):
            for i in range(0, self.row):
                temp[i] = self.data[i] + other.data[i]
            return Vector(temp)
        else:
            print("inconsistent types")
        return

    def __sub__(self, other):
        temp = numpy.zeros_like(self.data)
        if(self.row == other.row):
            for i in range(0, self.row):
                temp[i] = self.data[i] - other.data[i]
            return Vector(temp)
        else:
            print("inconsistent types")
        return

class Matrix:
    def __init__(self,data):
        if(data.ndim == 2):
            self.data = data
            self.row = data.shape[0]
            self.column = data.shape[1]
        else:
            print("error")

    def __add__(self, other):
        temp = numpy.zeros_like(self.data)
        if(self.row == other.row and self.column == other.column):
            for i in range(0, self.row):
                temp[i] = self.data[i] + other.data[i]
            return Matrix(temp)
        else:
            print("inconsistent types")
        return

    def __sub__(self, other):
        temp = numpy.zeros_like(self.data)
        if(self.row == other.row and self.column == other.column):
            for i in range(0, self.row):
                temp[i] = self.data[i] - other.data[i]
            return Matrix(temp)
        else:
            print("inconsistent types")
        return

