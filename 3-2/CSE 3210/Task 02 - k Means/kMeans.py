import numpy
import matplotlib.pyplot as plot
import matplotlib.cm as cm
import operator

random = lambda: numpy.random.randint(0, 1000)

def EuclideanDistance(PointOne, PointTwo):
    return numpy.sqrt(((PointOne[0]-PointTwo[0])**2)+((PointOne[1]-PointTwo[1])**2))

class Centroid():
    def __init__(self, CentroidPosition):
        self.CentroidPosition   = CentroidPosition
        self.points             = []
        self.PreviousPoints     = []
        self.color              = None
    
class kMeans():
    def __init__(self, NumberOfCentroids):
        self.NumberOfCentroids  = NumberOfCentroids
        self.Centroids          = []
        
        colors = cm.rainbow(numpy.linspace(0, 1, self.NumberOfCentroids))
        for i in range(NumberOfCentroids):
            self.Centroids.append(Centroid(numpy.array([random(), random()])))
            self.Centroids[i].color = colors[i]
    
    def GenerateSampleData(self, NumberOfPoints):
        self.Points = [[random(), random()] for iter in range(NumberOfPoints)]
    
    def fit(self):
        isComplete = False 
        while not isComplete:
            for point in self.Points:
                closest = self.findClosestPoint(point)
                closest.points.append(point)

            if len([c for c in self.Centroids if c.points == c.PreviousPoints]) == self.NumberOfCentroids:
                isComplete = True
            else:
                self.UpdateCentroids()
        self.show()
    
    def findClosestPoint(self, point):
        distances = {}
        for centroid in self.Centroids:
            distances[centroid] = EuclideanDistance(centroid.CentroidPosition, point)
        closest = min(distances.items(), key=operator.itemgetter(1))[0]
        return closest
    
    def UpdateCentroids(self):
        for centroid in self.Centroids:
            centroid.PreviousPoints = centroid.points
            xCo = [x[0] for x in centroid.points]
            yCo = [y[1] for y in centroid.points]
            try:
                # in case any point becomes zero
                centroid.CentroidPosition[0] = sum(xCo)/len(xCo)
                centroid.CentroidPosition[1] = sum(yCo)/len(yCo)
            except:
                pass
    
    def show(self):
        for i, c in enumerate(self.Centroids):
            plot.scatter(c.CentroidPosition[0], c.CentroidPosition[1], marker='o', color=c.color, s=75)
            xCo = [x[0] for x in c.points]
            yCo = [y[1] for y in c.points]
            plot.scatter(xCo, yCo, marker='.', color=c.color)

        plot.xlabel('X')
        plot.ylabel('Y')
        plot.title('kMeans')
        plot.show()



#main
KM = kMeans(int(input("Enter the number of Centroids: ")))
KM.GenerateSampleData(int(input("Enter the number of Sample data: ")))
KM.fit()