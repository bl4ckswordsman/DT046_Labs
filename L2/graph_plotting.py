import pandas as pd
import matplotlib.pyplot as plt
import numpy as np
from scipy.optimize import curve_fit


# import matplotlib
# matplotlib.use('Qt5Agg')

def plot_data(file_name):
    # Read in the data file using pandas
    df = pd.read_csv(file_name, delim_whitespace=True, skiprows=1)

    # Set the plot title
    with open(file_name) as f:
        plot_title = f.readline().strip()

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
    plt.errorbar(n, mean_time_ms, yerr=stdev_ms, fmt='o-', capsize=5, label='Data')
    plt.plot(x_new, y_new, '-', label='Fit')

    # Set the title and axis labels
    plt.title(plot_title)
    plt.xlabel('N')
    plt.ylabel('Mean time [ms]')
    plt.legend()

    # Display the plot
    plt.show()


plot_data('cmake-build-release/table.txt')
