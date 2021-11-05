import numpy
import scipy
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt
from scipy.interpolate import InterpolatedUnivariateSpline

#APERTURA E LETTURA DEL FILE
V, I, DV, DI= numpy.loadtxt('Polarizzazione_inversa.txt', unpack=True)
x=V
y=I
dx= DV
dy= DI

# Generate the datasets: a straight line + gaussian fluctuations
#DA ELIMINARE QUANDO AVREMO I NOSTRI DATI

#definition of the function
def fit_model(x, m, q):
    return m * x + q

x = numpy.linspace(0., 1., 20)
y = fit_model(x, 2., 10.) + numpy.random.normal(0, 0.1, len(x))
dy= y /100

#Definition of the spline function to interpolate the data with a polinomial funcition
spline=InterpolatedUnivariateSpline(x, y) #building the spline


#Plotting the graphs
lin = numpy.linspace(0.0, numpy.max(x), 100)
plt.figure('fit with custom callable')
plt.errorbar(x, y, dy, fmt='+')
plt.plot(lin, spline(lin))
plt.show()
