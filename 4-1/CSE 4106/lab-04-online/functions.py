import numpy as np


def calculate_entropy(img):
    marg = np.histogramdd(np.ravel(img), bins = 256)[0]/img.size
    marg = list(filter(lambda p: p > 0, np.ravel(marg)))
    entropy = -np.sum(np.multiply(marg, np.log2(marg)))
    return entropy

def spatial(img, const=10):
    rows, columns = img.shape
    pred1 = np.zeros((rows+1, columns+1))
    pred11 = pred1.copy()

    pred1[0, :] = const * np.ones((1, columns+1))
    pred1[1:rows+1, 0] = const*np.ones((rows,1))
    pred1[1:rows+1, 1:columns+1] = img
    for i in range(1, rows):
        for j in range(1, columns):
            pred11[i,j] = 0.5*(pred1[i, j-1] + pred1[i-1, j])
    
    pred11 = pred11[1:rows+1, 1:columns+1]
    pred11 = img - np.fix(pred11)

    return pred11

def temporal_sptl2(img, case, const=5):
    rows, columns = img.shape
    pred1 = np.zeros(rows+1, columns+1)
    pred11 = pred1.copy()
    
    pred1[0, :] = const*np.ones((1, columns+1))
    pred1[1:rows+1, 0] = const*np.ones((rows,1))
    pred1[1:rows+1, 1:columns+1] = img

    for i in range(1, rows):
        for j in range(1, columns):
            if case==1:
                pred11[i,j] = pred1[i-1, j]
            elif case==2:    
                pred11[i,j] = pred1[i-1, j-1]
            elif case==3:    
                pred11[i,j] = pred1[i, j-1]
            elif case==4:
                pred11[i,j] = 0.5*(pred1[i, j-1] + pred1[i-1, j])
            elif case==5:
                pred11[i,j] = pred1[i, j-1] + pred1[i-1, j] - pred1[i-1, j-1]
            elif case==6:
                pred11[i,j] = pred1[i, j-1] + ((pred1[i-1, j] - pred1[i-1, j-1])*0.5)
            else:
                pred11[i,j] = pred1[i-1, j] + ((pred1[i, j-1] - pred1[i-1, j-1])*0.5)

    pred11 = pred11[1:rows+1, 1:columns+1]
    pred11 = img - np.fix(pred11)
    pred11 = pred11.astype('double')

    return pred11

def loco_i(img, const=50):
    rows, columns = img.shape
    
    pred1 = np.zeros((rows+1, columns+1))
    pred11 = pred1.copy()
    
    pred1[0, :] = const*np.ones((1, columns+1))
    pred1[1:rows+1, 0] = const*np.ones((rows, 1))
    pred1[1:rows+1, 1:columns+1] = img
    
    for i in range(1, rows):
        for j in range(1, columns):
            if(pred1[i-1, j-1] >= max(pred1[i, j-1], pred1[i-1, j])):
                pred11[i,j] = min(pred1[i, j-1], pred1[i-1, j])
            elif(pred1[i-1, j-1] <= min(pred1[i, j-1], pred1[i-1, j])):
                pred11[i,j] = max(pred1[i, j-1], pred1[i-1, j])
            else:
                pred11[i,j] = pred1[i, j-1] + pred1[i-1, j] - pred1[i-1, j-1]
    
    pred11 = pred11[1:rows+1, 1:columns+1]
    pred11 = pred11.astype('int64')
    pred11 = pred11.astype('double')
