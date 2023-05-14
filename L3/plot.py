import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit

import matplotlib

matplotlib.use('Qt5Agg')


# Get the point label from the plot title of the format "XXXXX_sort_LABEL"
def get_point_lab(plot_title):
    return plot_title  # [plot_title.index("_sort_") + len("_sort_"):]


def function_fit(x, a, b, c):
    return a * x ** 2 + b * x + c


def function_fit_log(x, a, b):
    return a * np.log(x) + b


def plot_data(file_name, fit_func_expr, is_log=False):
    # Read in the data file using pandas
    df = pd.read_csv(file_name, delim_whitespace=True, skiprows=0)

    # Set the plot title
    # with open(file_name) as f:
    #     plot_title_temp = f.readline().strip()
    plot_title = ""  # plot_title_temp[:plot_title_temp.index("sort") + len("sort")]

    # Set the first column as the index
    df = df.set_index('N')

    # Get the data values
    n = df.index.values
    mean_time_ms = df['T[ms]'].values
    stdev_ms = df['Stdev[ms]'].values

    # Fit a polynomial function to the data

    if is_log:
        popt, _ = curve_fit(function_fit_log, n, mean_time_ms)
        x_new = np.linspace(n[0], n[-1], 100)
        y_new = function_fit_log(x_new, *popt)
    else:
        popt, _ = curve_fit(function_fit, n, mean_time_ms)
        # Create the plot
        x_new = np.linspace(n[0], n[-1], 100)
        y_new = np.polyval(popt, x_new)

    point_lab = ""  # get_point_lab(plot_title_temp)
    plt.errorbar(n, mean_time_ms, yerr=stdev_ms, fmt='o', capsize=5, label=point_lab)  # 'o-' for line
    plt.plot(x_new, y_new, '-', label=fit_func_expr + ' (approx.fit)')  # point_lab)     # , label='Fit'

    # Set the title and axis labels
    plt.title(plot_title)
    plt.xlabel('N')
    plt.ylabel('Mean time [ms]')
    plt.legend()


prefix = 'benchmark_results/'

# Insertion sort
plt.figure('Linear search')
plot_data(prefix + 'linear_search.txt', '')
plt.figure('Binary search')
plot_data(prefix + 'binary_search.txt', '', True)
plt.figure('Binary search tree')
plot_data(prefix + 'binary_tree_search.txt', '')

# Display the plot
plt.show()
