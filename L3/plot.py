import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit
import matplotlib

matplotlib.use('Qt5Agg')

prefix = 'benchmark_results/'
prf_img = 'benchmark_results/img/'


def get_plot_title(file_name, prefix):
    plot_title = file_name.replace(prefix, "")
    plot_title = plot_title.replace(".txt", "")
    return plot_title

def function_fit_lin(x, c):
    return np.full_like(x, c)

def function_fit(x, a, b, c):
    return a * x ** 2 + b * x + c


def function_fit_log(x, a, b):
    return a * np.log(x) + b


def plot_data(file_name, fit_func_expr, type='exp'):
    # Read in the data file using pandas
    df = pd.read_csv(file_name, delim_whitespace=True, skiprows=0)
    # Set the plot title
    plot_title = get_plot_title(file_name, prefix)
    # Set the first column as the index
    df = df.set_index('N')
    # Get the data values
    n = df.index.values
    mean_time_ms = df['T[ms]'].values
    stdev_ms = df['Stdev[ms]'].values
    # Fit a polynomial function to the data
    if type == 'log':
        popt, _ = curve_fit(function_fit_log, n, mean_time_ms)
        x_new = np.linspace(n[0], n[-1], 100)
        y_new = function_fit_log(x_new, *popt)
    elif type == 'exp':
        popt, _ = curve_fit(function_fit, n, mean_time_ms)
        # Create the plot
        x_new = np.linspace(n[0], n[-1], 100)
        y_new = np.polyval(popt, x_new)
    else:
        popt, _ = curve_fit(function_fit_lin, n, mean_time_ms)
        x_new = np.linspace(n[0], n[-1], 100)
        y_new = function_fit_lin(x_new, *popt)
    point_lab = ""  # get_point_lab(plot_title_temp)
    plt.errorbar(n, mean_time_ms, yerr=stdev_ms, fmt='o', capsize=5, label=point_lab)  # 'o-' for line
    plt.plot(x_new, y_new, '-', label=fit_func_expr + ' (approx.fit)')  # point_lab)     # , label='Fit'
    # Set the title and axis labels
    plt.title(plot_title)
    plt.xlabel('N')
    plt.ylabel('Mean time [ms]')
    plt.legend()
    plt.ylim(bottom=0)
    plt.xlim(left=0)
    plt.grid(True)
    # Save the plot as an image file
    # plt.savefig(prf_img + plot_title + '.png')


plt.figure('Linear search')
plot_data(prefix + 'linear_search.txt', 'N', 'exp')
plt.figure('Binary search')
plot_data(prefix + 'binary_search.txt', 'logN', 'log')
plt.figure('Binary search tree')
plot_data(prefix + 'binary_tree_search.txt', 'logN', 'log')
plt.figure('Hash table')
plot_data(prefix + 'hash_table_search.txt', '1', 'lin')

# Display the plot
plt.show()
