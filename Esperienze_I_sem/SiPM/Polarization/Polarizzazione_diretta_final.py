import numpy
import scipy
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt

#APERTURA E LETTURA DEL FILE
V, I= numpy.loadtxt('Dati/Polarizzazione_diretta/20211102_163215.txt', unpack=True)
#Sto riportando a valori positivi le tensioni e la corrente
x=numpy.absolute(V)
y=numpy.absolute(I)
#dx= DV
dy= numpy.absolute((x+1)/100) #erorri messi a caso! da rivedere

'''Maschera da applicare ai dati sopra la tensione soglia
della giunzione a circa 0.6V
'''
mask1 = x>= 0.65
xfit=x[mask1]
yfit=y[mask1]
dyfit=dy[mask1]

#Definisco gli array di dati esclusi dal fit
mask2= x<0.65
xesc= x[mask2]
yesc= y[mask2]
dyesc= dy[mask2]

#definition of the function
def fit_model(x, m, q):
    return m * x + q


#Fit (da cambiare parametri della funzione)
popt, pcov = curve_fit(fit_model, xfit, yfit, p0=[-1., -100.])
m, q = popt
sigma_m, sigma_q = numpy.sqrt(pcov.diagonal())
print(f'm = {m:.2f} +- {sigma_m:.2f} [nA/V]')
print(f'q = {q:.2f} +- {sigma_q:.2f} [nA]' )

#Riportiamo m e q in Ampere su Volt e Ampere
m_A= m/(10**9)
q_A= q/(10**9)
sigma_mA= sigma_m/(10)**9
sigma_qA= sigma_q/(10)**9

print(f'm_A = {m_A: .5f} +- {sigma_mA: .5f} [A/V]')
print(f'q_A = {q_A} +- {sigma_qA} [A]' )


#Plotting the graphs
lin = numpy.linspace(0.0, numpy.max(x), 100)
plt.figure('Curva I-V polarizzazione diretta')
plt.title('Curva I-V polarizzazione diretta')
plt.xlabel('Tensione di alimentazione SiPM [V]')
plt.ylabel('Corrent [nA]')

plt.errorbar(xfit, yfit, dyfit, fmt='+', color='Blue', label='Data')
plt.errorbar(xesc, yesc, dyesc, fmt='+', color='Green', label='Masked values' )
plt.plot(lin, fit_model(lin, m, q), color='Red', label='Fit' )
plt.legend()
plt.grid(True)
plt.show()
print(len(dy))



#Calcolo chi2
sigma_y = dyfit #da cambiare all'occorrenza
chisq = (((yfit - fit_model(xfit, *popt)) / sigma_y) **2).sum()
print(f'chiquadro = {chisq:.1f}')

#Calcolo di R
N=667
R_q=N/m_A
sigma_R=sigma_m*(N/(m_A)**2)
print(f'R_q= {R_q} +- {sigma_R}')
