# Machine Learning Lab 2

---
# Data Preprocessing Techniques 

## Handling the missing values

- [gfg-article-link](https://www.geeksforgeeks.org/ml-handling-missing-values/)

### **Comparison of Mean, Median, and Mode Imputation**


### **Comparison Table**

| **Criteria**              | **Mean**                                   | **Median**           | **Mode**                                           |
|---------------------------|--------------------------------------------|----------------------|----------------------------------------------------|
| **Data Type**             | Numerical                                  | Numerical            | Categorical (or Numerical with duplicates)         |
| **Affected by Outliers?** | Yes                                        | No                   | No                                                 |
| **Best for**              | Symmetric distributions                    | Skewed distributions | Categorical data                                   |
| **Drawback**              | Sensitive to outliers; reduces variability | Reduces variability  | May introduce bias towards the most frequent value |


### **Conclusion**
- Choose **mean imputation** for numerical data that is approximately normally distributed.
- Use **median imputation** for numerical data with skewness or outliers.
- Opt for **mode imputation** when dealing with categorical data or numerical data with many repeated values.

--- 

# Data Transformation 

## **Min-max Scaling** 

**Min-Max Scaling** is a common data preprocessing technique in machine learning. It is used to rescale features of your data to a specific range, typically [0, 1]. The purpose is to normalize the range of independent variables or features to make them comparable and avoid issues where some features dominate because of their larger scale.



### Why Use Min-Max Scaling?

1. **Normalization of Features**:
    - Ensures all features contribute equally to the model's calculations.
    - Avoids dominance of features with larger scales.

2. **Improved Model Performance**:
    - Algorithms like gradient descent converge faster when the data is normalized.
    - Distance-based algorithms (e.g., K-Nearest Neighbors, K-Means, SVM with RBF kernel) are sensitive to the scale of features.

3. **Feature Comparability**:
    - Helps in comparing features that have different units or scales (e.g., age in years vs. income in dollars).


### When Not to Use Min-Max Scaling

- If the data contains significant outliers, Min-Max scaling can compress the range of the other data points. In such cases, consider using **RobustScaler** or **StandardScaler**.
- After scaling, the values lose their original units or meaning (e.g., income in dollars or age in years), which may make the results harder to interpret without context.

---

## **Mean Normalization**

**Mean-normalization** is a feature scaling technique in ml and data processing . it adjusts the value of dataset so that it is centered around zero (mean = 0).

### Why Use Mean Normalization ?


1. **Normalization of Features**:
    - Ensures all features contribute equally to the model's calculations.
    - Avoids dominance of features with larger scales.

2. **Improved Model Performance**:
    - Algorithms like gradient descent converge faster when the data is normalized.
    - Distance-based algorithms (e.g., K-Nearest Neighbors, K-Means, SVM with RBF kernel) are sensitive to the scale of features.

3. **Feature Comparability**:
    - Helps in comparing features that have different units or scales (e.g., age in years vs. income in dollars).

### Disadvantages of Mean Normalization 

1. **Sensitives to Outliers** :
   While it centers the data around zero (by subtracting the mean), it is still influenced by extreme outliers, as the mean itself can be heavily affected by them.

> **Note:**  
> **Mean normalization** does **not** make a skewed distribution into a normal distribution. It only shifts the data to have a mean of zero and may scale it.  
> To actually transform a skewed distribution into a more normal shape, you would need to apply specific techniques like **log transformation**, **Box-Cox**, or **Yeo-Johnson transformations**.

---

## **Standardization (Z score)**

**Standardization** is a feature scaling technique used in machine learning to transform data so that it has a mean of zero and a standard deviation of one. This process ensures that each feature contributes equally to the model's learning process, especially for algorithms sensitive to the scale of data.




### **When Should You Use Standardization?**

1. **Algorithms That Require Standardized Data**:
    - **Gradient-based algorithms**: Linear regression, logistic regression, and neural networks.
    - **Distance-based algorithms**: K-means clustering, k-nearest neighbors (KNN), and principal component analysis (PCA).
    - **Support Vector Machines (SVM)**: Since they calculate distances to hyperplanes.

2. **Datasets with Features on Different Scales**:
    - For example, a dataset containing features like weight (in kilograms) and height (in meters). Their magnitudes are vastly different, requiring standardization.

3. **When Dealing with Skewed or Imbalanced Ranges**:
    - Features with outliers or significantly different variances benefit from standardization to align their contribution.


### **Difference Between Standardization and Normalization**

| **Aspect**                 | **Standardization**                                                    | **Normalization**                                               |
|----------------------------|------------------------------------------------------------------------|-----------------------------------------------------------------|
| **Definition**             | Transforms data to have a mean of 0 and standard deviation of 1.       | Scales data to fit within a fixed range, often [0, 1].          |
| **Effect on Distribution** | Maintains the original shape of the distribution.                      | Compresses data into the specified range, altering the shape.   |
| **Use Case**               | Used in algorithms that assume normality or are sensitive to variance. | Used when absolute range is important (e.g., image processing). |


### **Advantages of Standardization**

1. **Robustness to Different Units**:
    - Works well when features are measured in different units (e.g., centimeters vs. kilograms).

2. **Preserves Outlier Information**:
    - Unlike normalization, which compresses values to a range, standardization retains the relative scale of data points, preserving outliers.

3. **Consistency in Models**:
    - Standardization ensures consistency when applying machine learning algorithms that depend on the scale of features.


### **Limitations of Standardization**

1. **Assumes Normal Distribution**:
    - Standardization works best when the feature's values follow a Gaussian (normal) distribution. For heavily skewed data, it may not be effective.

2. **Sensitive to Outliers**:
    - The mean and standard deviation can be influenced by outliers, leading to skewed standardized values.

3. **Not Always Necessary**:
    - Tree-based models (e.g., decision trees, random forests, gradient boosting) are scale-invariant and do not require standardization.

> **Note:**  
> **Standard deviation** or **standardization** does **not** convert a skewed distribution into a normal distribution. It only scales the data to have a mean of zero and a standard deviation of one.  
> To transform a skewed distribution into a more normal shape, use techniques like **log transformation**, **Box-Cox**, or **Yeo-Johnson transformations**.

--- 