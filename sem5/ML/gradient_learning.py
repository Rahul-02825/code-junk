import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split

# Load the dataset
data = pd.read_csv("C:\Users\rahul\Downloads\DIABETICS DATASET.csv")

# Select features and target
top_features = ['Glucose', 'BMI']
X = data[top_features].values
y = data['Outcome'].values

# Balance the dataset
class_0 = data[data["Outcome"] == 0]
class_1 = data[data["Outcome"] == 1]
class_0 = class_0.sample(n=len(class_1), random_state=42)
data_balanced = pd.concat([class_0, class_1])

X = data_balanced[top_features].values
y = data_balanced['Outcome'].values

# Split the data into training and testing sets
X_train, X_test, y_train, y_test = train_test_split(X, y, test_size=0.2, random_state=42)

# Normalize the features
X_train = (X_train - np.mean(X_train, axis=0)) / np.std(X_train, axis=0)
X_test = (X_test - np.mean(X_test, axis=0)) / np.std(X_test, axis=0)

# Sigmoid function
def sigmoid(z):
    return 1 / (1 + np.exp(-z))

# Initialize parameters
m, n = X_train.shape
theta = np.zeros(n + 1)  # Including bias term
X_train = np.c_[np.ones((m, 1)), X_train]  # Add bias term to X_train

# Learning rate and number of iterations
learning_rate = 0.01
iterations = 1000

# Gradient Descent
for _ in range(iterations):
    z = np.dot(X_train, theta)
    h = sigmoid(z)
    gradient = np.dot(X_train.T, (h - y_train)) / m
    theta -= learning_rate * gradient

# Predicting on the test set
X_test = np.c_[np.ones((X_test.shape[0], 1)), X_test]  # Add bias term to X_test
y_predict = sigmoid(np.dot(X_test, theta))
y_pred = (y_predict >= 0.5).astype(int)

# Confusion Matrix
tp = np.sum((y_test == 1) & (y_pred == 1))
tn = np.sum((y_test == 0) & (y_pred == 0))
fp = np.sum((y_test == 0) & (y_pred == 1))
fn = np.sum((y_test == 1) & (y_pred == 0))

confusion_matrix = np.array([[tn, fp], [fn, tp]])
print("Confusion Matrix:\n", confusion_matrix)

# Accuracy
accuracy = (tp + tn) / len(y_test)
print("Accuracy:", accuracy)

# Plotting the Cost Function (Optional)
cost_history = []
for i in range(iterations):
    z = np.dot(X_train, theta)
    h = sigmoid(z)
    cost = -(1/m) * (np.dot(y_train.T, np.log(h)) + np.dot((1 - y_train).T, np.log(1 - h)))
    cost_history.append(cost)

plt.plot(range(iterations), cost_history)
plt.xlabel('Iterations')
plt.ylabel('Cost')
plt.title('Cost Function Over Iterations')
plt.show()
