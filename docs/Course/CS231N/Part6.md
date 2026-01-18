---
comments: true
---

<span style="font-family: 'Times New Roman';">

# Part6 Neural Networks Ⅱ

***

## Data Preprocessing

**Mean Subtraction (Zero-Centering):**

For $N$ input image, compute the mean image and subtract it from each input image.

**Normalization:**

For each pixel, compute the standard deviation over the training set and divide each pixel by its standard deviation.

**PCA & Whitening**

!!! Note
    **Common Pitfall:**

    Any preprocessing statistics must only be computed on the training data. When it comes to the validation or test data, simply apply them.

***

## Weight Initialization

It is recommended to use a zero mean, unit standard gaussian. Then, calibrate the variances with $\frac{1}{\sqrt{D}}$, where $D$ is the input dimensions.

**Batch Normalization:**

Between each fully-connected layer and activation function, force the data to take on a unit gaussian distribution.

***

## Regularization

**L2 Regularization**

$$\frac{1}{2}w^2$$

**L1 Regularization**

$$\lambda|w|$$

**Dropout:**

For each batch of training (a forward pass and a backward pass), randomly drop units (along with their connections) from the neural network. This prevents overfitting by ensuring that the model does not rely on any specific feature.

When it comes to validation or testing, do not drop any units but use the full network. However, do scale the outputs by $p$ (the probability of keeping a neuron active).