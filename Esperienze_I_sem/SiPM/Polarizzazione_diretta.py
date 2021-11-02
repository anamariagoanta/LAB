import numpy
import scipy
import callable
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

#APERTURA E LETTURA DEL FILE
V, I, DV, DI= numpy.loadtxt('Polarizzazione_diretta.txt', unpack=True)
x=V
y=I
dx= DV
dy= DI

#definition of the function
def fit_model(x, m, q):
    return m * x + q

# Generate the datasets: a straight line + gaussian fluctuations
#DA ELIMINARE QUANDO AVREMO I NOSTRI DATI

x = numpy.linspace(0., 1., 20)
y = fit_model(x, 2., 10.) + numpy.random.normal(0, 0.1, len(x))
dy= y /100
print(y)



#Fit (da cambiare parametri della funzione)
popt, pcov = curve_fit(fit_model, x, y, p0=[-1., -100.])
m, q = popt
sigma_m, sigma_q = numpy.sqrt(pcov.diagonal())
print(f'm = {m:.2f} +- {sigma_m:.2f}')
print(f'q = {q:.2f} +- {sigma_q:.2f}')

#Plotting the graphs
lin = numpy.linspace(0.0, numpy.max(x), 100)
plt.figure('fit with custom callable')
plt.errorbar(x, y, dy, fmt='+')
plt.plot(lin, fit_model(lin, m, q))
plt.show()
print(len(dy))



#Calcolo chi2
sigma_y = dy #da cambiare all'occorrenza
chisq = (((y - fit_model(x, *popt)) / sigma_y) **2).sum()
print(f'chiquadro = {chisq:.1f}')
