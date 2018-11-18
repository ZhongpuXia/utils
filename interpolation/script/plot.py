#!/usr/bin/env python

import numpy as np
from matplotlib import pyplot as plt
import argparse

def load(filename):
    """
    @Parameter
        - filename: (str) path to the data
    @Return:
        - start: (x, y, theta) PathPoint of the start point
        - end: (x, y, theta) PathPoint of the end point
        - path_point_list: (t, x, y, theta, kappa) lists interpolated between [start, end]
    """
    path_point_list = []
    with open(filename, 'r') as fi:
        for i, line in enumerate(fi.readlines()):
            if i == 0:
                start_str = line.split(':')[-1].split(', ')
                start_point = [float(s) for s in start_str]
                continue
            if i == 1:
                end_str = line.split(':')[-1].split(', ')
                end_point = [float(s) for s in end_str]
                continue
            line_seg = line.split(', ')
            path_point_list.append([float(s) for s in line_seg])
    return start_point, end_point, path_point_list

def plot(path_point_list):
    """
    plot the interpolated curve
    """
    t = []
    x = []
    y = []
    theta = []
    kappa = []
    for point in path_point_list:
        t.append(point[0])
        x.append(point[1])
        y.append(point[2])
        theta.append(point[3])
        kappa.append(point[4])
    plt.subplot(221)
    plt.plot(x, y, '.')
    plt.legend(['x-y'])
    plt.title("interpolated points")

    plt.subplot(222)
    plt.plot(t, theta, '.')
    plt.legend(['theta'])
    plt.title("point heading")

    plt.subplot(223)
    plt.plot(t, kappa, '.')
    plt.legend(['kappa'])
    plt.title("point curvature of the curve")

if __name__ == "__main__":
    parser = argparse.ArgumentParser(description="load and plot the path points generated by the spline")
    parser.add_argument("data_path", default="../results.txt", type=str, help="path to the data")

    args = parser.parse_args()
    filename = args.data_path
    start_point, end_point, path_point_list = load(filename)
    plot(path_point_list)
    plt.show()
