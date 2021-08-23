import numpy as np
import pandas as pd
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import plot_tree
from sklearn.model_selection import train_test_split
import matplotlib.pyplot as plt

dataset = pd.read_csv("https://raw.githubusercontent.com/rmShoeb/Datasets/master/pima-indians-diabetes.data.csv")
#print(dataset.head())

np_array = dataset.values
X = np_array[:,:8]
y = np_array[:,8]

X_train, X_test, y_train, y_test = train_test_split(X, y, test_size = 0.2, random_state=42)

clf = DecisionTreeClassifier()
clf = clf.fit(X_train,y_train)

#fig, ax = plt.subplots(figsize=(30, 30))
#plot_tree(clf, filled=True, fontsize=12)
#plt.show()

true_positive = true_negative = false_positive = false_negative = 0
test_length = len(X_test)
for iter in range(test_length):
  sample = X_test[iter].reshape(1, -1)
  prediction = clf.predict(sample)
  prediction = int(prediction[0])
  if prediction==1:
    if int(y[iter])==1:
      true_positive = true_positive+1
    else:
      false_positive = false_positive+1
  else:
    if int(y[iter])==1:
      false_negative = false_negative+1
    else:
      true_negative = true_negative+1

print("Confusion Matrix")
print("True positive: {}".format(true_positive))
print("True negative: {}".format(true_negative))
print("False positive: {}".format(false_positive))
print("False negative: {}".format(false_negative))

accuracy = (true_positive+true_negative)/(true_positive+false_positive+true_negative+false_negative)
print("Accuracy: {}".format(accuracy))

precision = (true_positive)/(true_positive+false_positive)
print("Precision: {}".format(precision))

sensitivity = (true_positive)/(true_positive+false_negative)
print("Sensitivity: {}".format(sensitivity))

specificity = (true_negative)/(true_negative+false_positive)
print("Specificity: {}".format(specificity))
