import numpy as np 
import pandas as pd 
from pprint import pprint

def P(numberOfOccurences, totalCase):
    try:
        return numberOfOccurences/totalCase
    except:
        return 0


class DecisionTree():
    def __init__(self, dataFrame):
        self.dataFrame = dataFrame
        self.data = dataFrame.values
        self.header = dataFrame.columns
        self.tree = {}
        self.generateTree(self.data, self.dataFrame)
    
    def IG(self, EOA, EOC):
        return EOC-EOA
    
    def calculateEntropy(self, column):
        _, classCounts = np.unique(column, return_counts=True)
        p = classCounts/classCounts.sum()
        entropy = sum(-p*np.log2(p))
        
        return entropy
    
    def generateTree(self, data, dataFrame):
        entropyOfClass = self.calculateEntropy(data[:, -1])
        maxInformationGain = 99
        column = 0
        selectedFeature = 0

        # selecting root/sub-root
        while column < (len(self.header)-1):
            uniqueLevels = np.unique(data[:,column])
            featureEntropy = 0
            for uniqueLevel in uniqueLevels:
                modifiedData = dataFrame[dataFrame[self.header[column]] == uniqueLevel].values #extracting the rows for the unique level
                featureEntropy += P(len(modifiedData), len(data))*self.calculateEntropy(modifiedData[:,-1])
            featureIG = self.IG(featureEntropy, entropyOfClass)
            if featureIG > maxInformationGain:
                maxInformationGain = featureIG
                selectedFeature = column
            column += 1
        # root selected 

        print(self.header[selectedFeature])

    def showTree(self):
        pprint(self.tree)


#main
dataFrame = pd.read_csv(input("Enter dataset name: "))
# dataFrame = pd.read_csv("DataSet.csv")
DT = DecisionTree(dataFrame)
print("Training Data:")
# print(dataFrame)
# DT.showTree()
print("Resultant Decision Tree:")
