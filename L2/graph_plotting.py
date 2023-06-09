import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit


# import matplotlib
# matplotlib.use('Agg')


# Get the point label from the plot title of the format "XXXXX_sort_LABEL"
def get_point_lab(plot_title):
    return plot_title[plot_title.index("_sort_") + len("_sort_"):]


def plot_data(file_name, fit_func_expr):
    # Read in the data file using pandas
    df = pd.read_csv(file_name, delim_whitespace=True, skiprows=1)

    # Set the plot title
    with open(file_name) as f:
        plot_title_temp = f.readline().strip()
    plot_title = plot_title_temp[:plot_title_temp.index("sort") + len("sort")]

    # Set the first column as the index
    df = df.set_index('N')

    # Get the data values
    n = df.index.values
    mean_time_ms = df['T[ms]'].values
    stdev_ms = df['Stdev[ms]'].values

    # Fit a polynomial function to the data
    popt, _ = curve_fit(lambda x, a, b, c: a * x ** 2 + b * x + c, n, mean_time_ms)

    # Create the plot
    x_new = np.linspace(n[0], n[-1], 100)
    y_new = np.polyval(popt, x_new)

    point_lab = get_point_lab(plot_title_temp)
    plt.errorbar(n, mean_time_ms, yerr=stdev_ms, fmt='o', capsize=5, label=point_lab)  # 'o-' for line
    plt.plot(x_new, y_new, '-', label=fit_func_expr + ' (approx.fit)')  # point_lab)     # , label='Fit'

    # Set the title and axis labels
    plt.title(plot_title)
    plt.xlabel('N')
    plt.ylabel('Mean time [ms]')
    plt.legend()


prefix = 'Test_results/'

# Insertion sort
plt.figure('Fig1')
plot_data(prefix + 'insert_sort_const.txt', '')
plot_data(prefix + 'insert_sort_monot_incr.txt', '')
plt.figure('Fig2')
plot_data(prefix + 'insert_sort_rand.txt', '')   # t=0.5N²
plot_data(prefix + 'insert_sort_monot_decr.txt', '')    # t=N²

# Selection sort
plt.figure('Fig3')
plot_data(prefix + 'select_sort_const.txt', '')     # t=N²
plot_data(prefix + 'select_sort_rand.txt', '')
plot_data(prefix + 'select_sort_monot_incr.txt', '')
plot_data(prefix + 'select_sort_monot_decr.txt', '')

# Right pivot quick sort
plt.figure('Fig4')

plot_data(prefix + 'right_pivot_quick_sort_rand.txt', '')   # t=NlogN
plt.figure('Fig5')
plot_data(prefix + 'right_pivot_quick_sort_const.txt', '')
plot_data(prefix + 'right_pivot_quick_sort_monot_incr.txt', '')
plot_data(prefix + 'right_pivot_quick_sort_monot_decr.txt', '')

# Median of three pivot quick sort
plt.figure('Fig6')
plot_data(prefix + 'medof3_quick_sort_const.txt','')
plt.figure('Fig6.1')
plot_data(prefix + 'medof3_quick_sort_rand.txt', '')
plot_data(prefix + 'medof3_quick_sort_monot_incr.txt', '')
plot_data(prefix + 'medof3_quick_sort_monot_decr.txt', '')

# std::sort
plt.figure('Fig7')
plot_data(prefix + 'std_sort_const.txt', '')
plot_data(prefix + 'std_sort_rand.txt', '')
plot_data(prefix + 'std_sort_monot_incr.txt', '')
plot_data(prefix + 'std_sort_monot_decr.txt', '')


# Display the plot
plt.show()
