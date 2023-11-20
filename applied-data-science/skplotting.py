import numpy as np
import matplotlib.pyplot as plt
from itertools import combinations


def plot_contours(ax, clf, X, x_idx, y_idx, h=.02, **params):
    x_min, x_max = X[:, x_idx].min() - 1, X[:, x_idx].max() + 1
    y_min, y_max = X[:, y_idx].min() - 1, X[:, y_idx].max() + 1
    xx, yy = np.meshgrid(
        np.arange(x_min, x_max, h), np.arange(y_min, y_max, h)
    )
    X_predict = np.tile(np.mean(X, axis=0), (xx.shape[0]*xx.shape[1], 1))
    X_predict[:, x_idx] = xx.ravel()
    X_predict[:, y_idx] = yy.ravel()
    Z = clf.predict(X_predict)
    Z = Z.reshape(xx.shape)
    out = ax.contourf(xx, yy, Z, **params)
    return out


def plot_decision_boundary(
    ax, clf, X, y, classes, x_idx, y_idx, h=.02, colourmap=plt.cm.viridis
):
    x_min, x_max = X[:, x_idx].min() - 1, X[:, x_idx].max() + 1
    y_min, y_max = X[:, y_idx].min() - 1, X[:, y_idx].max() + 1
    xx, yy = np.meshgrid(
        np.arange(x_min, x_max, h), np.arange(y_min, y_max, h)
    )
    X_predict = np.tile(
        np.mean(X, axis=0), (xx.shape[0]*xx.shape[1], 1)
    )
    X_predict[:, x_idx] = xx.ravel()
    X_predict[:, y_idx] = yy.ravel()
    Z = clf.predict(X_predict)
    Z = Z.reshape(xx.shape)
    ax.contourf(xx, yy, Z, cmap=colourmap, alpha=0.8)
    scatter = ax.scatter(
        X[:, x_idx], X[:, y_idx], c=y, cmap=colourmap, s=20, edgecolors='k'
    )
    handles, labels = scatter.legend_elements()
    legend1 = ax.legend(handles, classes, title="Classes")
    ax.add_artist(legend1)
    return ax


def plot_pair_decision_boundaries(
    clf, X, y, classes, features, h=.02, colourmap=plt.cm.viridis
):
    nrows = (X.shape[0]//3)+1
    fig, ax = plt.subplots(nrows, 3, figsize=(12, 4*nrows))
    for idx, pair in enumerate(combinations(enumerate(features), 2)):
        plot_decision_boundary(
            ax[idx // 3, idx % 3], clf, X, y, classes, pair[0][0], pair[1][0],
            h=h, colourmap=colourmap
        )
        ax[idx // 3, idx % 3].set_xlabel(pair[0][1])
        ax[idx // 3, idx % 3].set_ylabel(pair[1][1])
    plt.show()
