import numpy as np 
import pandas as pd 
import matplotlib.pyplot as plt 
import seaborn as sns
from pprint import pprint
import random

def trainTestSplit(dataFrame, testSize=20):
    testIndices = random.sample(population=dataFrame.index.tolist(), k=testSize)
    
    testDataFrame = dataFrame.loc[testIndices]
    trainDataFrame = dataFrame.drop(testIndices)

    return trainDataFrame, testDataFrame

def isPure(data):
    return len(np.unique(data[:,-1])) == 1

def classifyData(data):
    uniqueClasses, uniqueClassesCount = np.unique(data[:,-1], return_counts=True)
    return uniqueClasses[uniqueClassesCount.argmax()]

def getPotentialSplits(data):
    potentialSplits = {}
    _, numberOfColumns = data.shape
    
    for column in range(numberOfColumns-1):
        potentialSplits[column] = []
        uniqueValues = np.unique(data[:,column])
        
        for index in range(len(uniqueValues)):
            if index != 0:
                #currentValue = uniqueValues[index]
                #previousValue = uniqueValues[index-1]
                #potentialSplit = (currentValue+previousValue)/2
                potentialSplits[column].append((uniqueValues[index]+uniqueValues[index-1])/2)
    
    return potentialSplits

def splitData(data, splitAlongColumn, splitByValue):
    dataBelow = data[data[:,splitAlongColumn] <= splitByValue]
    dataAbove = data[data[:,splitAlongColumn] > splitByValue]
    
    return dataBelow, dataAbove

def calculateEntropy(data):
    _, classCounts = np.unique(data[:,-1], return_counts=True)
    p = classCounts/classCounts.sum()
    entropy = sum(p*np.log2(p))
    
    return entropy

def calculateOverallEntropy(dataBelow, dataAbove):
    numberOfDataPoints = len(dataBelow)/len(dataAbove)
    pDataBelow = len(dataBelow)/numberOfDataPoints
    pDataAbove = len(dataAbove)/numberOfDataPoints
    overallEntropy = (pDataBelow*calculateEntropy(dataBelow)) * (pDataAbove*calculateEntropy(dataAbove))
    
    return overallEntropy

def determineBestSplit(data, potentialSplits):
    overallEntropy = 999

    for column in potentialSplits:
        for value in potentialSplits[column]:
            dataBelow, dataAbove = splitData(data, splitAlongColumn=column, splitByValue=value)
            currentOverallEntropy = calculateOverallEntropy(dataBelow, dataAbove)
            if currentOverallEntropy <= overallEntropy:
                overallEntropy = currentOverallEntropy
                bestSplitColumn = column
                bestSplitValue = value

    return bestSplitColumn, bestSplitValue


#def entropy(y):
    #hist = np.bincount(y)
    #ps = hist/len(y)
    #return -np.sum([p*np.log2(p) for p in ps if p>0])


#main
#dataFrame = pd.read_csv(input("Enter dataset name: "))
dataFrame = pd.read_csv("iris.csv")
print("Training Data:")
print(dataFrame)

getPotentialSplits(dataFrame.values)
#sns.lmplot(data=dataFrame,x="petalwidth", y="petallength", hue="class")
#plt.show()
print(calculateEntropy(dataFrame.values))

print("Resultant Decision Tree:")
