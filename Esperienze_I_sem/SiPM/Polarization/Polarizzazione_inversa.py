import numpy
import scipy
from scipy.optimize import curve_fit
import matplotlib.pyplot as plt
from scipy.interpolate import InterpolatedUnivariateSpline

#APERTURA E LETTURA DEL FILE DARK
V_dark, I_dark= numpy.loadtxt('Dati/Polarizzazione_inversa/20211102_165125_NoLuce_58_0.5_2.txt', unpack=True)
x1=V_dark
y1=I_dark
#dx= DV

dy1= y1*(3/100) #diamo un errore simbolico del 3%


#APERTURA E LETTURA DEL FILE LUCE700nA
V_luce1, I_luce1= numpy.loadtxt('Dati/Polarizzazione_inversa/20211102_171652_luce700nA_58_0.5_2.txt', unpack=True)
x2=V_luce1
y2=numpy.absolute(I_luce1)
#dx= DV

dy2= y2*(3/100)

#APERTURA E LETTURA DEL FILE LUCE700nA
V_luce2, I_luce2= numpy.loadtxt('Dati/Polarizzazione_inversa/20211102_172509_luce100muA_58_0.5_2.txt', unpack=True)
x3=V_luce2
y3=numpy.absolute(I_luce2)
#dx= DV

dy3= y3*(3/100)


#definition of the function
def fit_model(x, m, q):
    return m * x + q

#Fit con una parabola oltre il breakdown
def parabola(x, a, b, c):
    return a*x*x + b*x +c

#Maschere dei dati per prendere i valori oltre il breakdown
#maschera 1
mask1 = x1>= 53.1
x_fit1=x1[mask1]
y_fit1=y1[mask1]
dy_fit1=dy1[mask1]

mask1_2 = x1 < 53.1
x_masked1=x1[mask1_2]
y_masked1=y1[mask1_2]
dy_masked1=dy1[mask1_2]

#maschera 2
mask2 = x2>= 53.1
x_fit2=x2[mask2]
y_fit2=y2[mask2]
dy_fit2=dy2[mask2]

mask2_2 = x2 < 53.1
x_masked2=x2[mask2_2]
y_masked2=y2[mask2_2]
dy_masked2=dy2[mask2_2]

#maschera 3
mask3 = x3>= 53.1
x_fit3=x3[mask3]
y_fit3=y3[mask3]
dy_fit3=dy3[mask3]

mask3_2 = x3 < 53.1
x_masked3=x3[mask3_2]
y_masked3=y3[mask3_2]
dy_masked3=dy3[mask3_2]

#Fit 1
popt1, pcov1 = curve_fit(parabola, x_fit1, y_fit1, p0=[1., 0., 0.])
a1, b1, c1 = popt1
sigma_a1, sigma_b1, sigma_c1 = numpy.sqrt(pcov1.diagonal())
print(f'a1 = {a1:.10f} +- {sigma_a1:.2f} [???]')
print(f'b1 = {b1:.10f} +- {sigma_b1:.2f} [???]' )
print(f'c1 = {c1:.10f} +- {sigma_c1:.2f} [???]')

#Fit 2
popt2, pcov2 = curve_fit(parabola, x_fit2, y_fit2, p0=[1., 0., 0.])
a2, b2, c2 = popt2
sigma_a2, sigma_b2, sigma_c2 = numpy.sqrt(pcov2.diagonal())
print(f'a2 = {a2:.10f} +- {sigma_a2:.2f} [???]')
print(f'b2 = {b2:.10f} +- {sigma_b2:.2f} [???]' )
print(f'c2 = {c2:.10f} +- {sigma_c2:.2f} [???]')

#Fit 3
popt3, pcov3 = curve_fit(parabola, x_fit3, y_fit3, p0=[1., 0., 0.])
a3, b3, c3 = popt3
sigma_a3, sigma_b3, sigma_c3 = numpy.sqrt(pcov3.diagonal())
print(f'a3 = {a3:.10f} +- {sigma_a3:.2f} [???]')
print(f'b3 = {b3:.10f} +- {sigma_b3:.2f} [???]' )
print(f'c3 = {c3:.10f} +- {sigma_c3:.2f} [???]')

#Calcolo chi2 1
sigma_y=dy_fit1
chisq1 = (((y_fit1 - parabola(x_fit1, *popt1)) / sigma_y) **2).sum()
NDOF1=len(x_fit1)-len(popt1)
print(f'chiquadro1 = {chisq1:.2f} con NDOF1 = {NDOF1}')

#Calcolo chi2 2
sigma_y=dy_fit2
chisq2 = (((y_fit2 - parabola(x_fit2, *popt2)) / sigma_y) **2).sum()
NDOF2=len(x_fit2)-len(popt2)
print(f'chiquadro2 = {chisq2:.2f} con NDOF2 = {NDOF2}')

#Calcolo chi2 3
sigma_y=dy_fit3
chisq3 = (((y_fit3 - parabola(x_fit3, *popt3)) / sigma_y) **2).sum()
NDOF3=len(x_fit3)-len(popt3)
print(f'chiquadro3 = {chisq3:.2f} con NDOF3 = {NDOF3}')


#Definition of the spline function to interpolate the data with a polinomial funcition
spline1=InterpolatedUnivariateSpline(x1, y1) #building the spline for dark
spline2=InterpolatedUnivariateSpline(x2, y2) #building the spline for good light level
spline3=InterpolatedUnivariateSpline(x3, y3) #building the spline for light level too hight


#Plotting the graphs
plt.figure('Curva I-V polarizzazione inversa')
plt.title('Curva I-V polarizzazione inversa')

plt.xlabel('Tensione di alimentazione SiPM [V]')
plt.ylabel('Corrent [nA]')
plt.yscale('log')
lin = numpy.linspace(0.0, numpy.max(x1), 1000)
plt.errorbar(x1, y1, dy1, fmt='+', color='Blue', label='Data Dark')
plt.plot(lin, spline1(lin), color='cornflowerblue', label='Dark')
plt.errorbar(x2, y2, dy2, fmt='+', color='Green', label='Data good light level')
plt.plot(lin, spline2(lin), color='limegreen', label='Good light level')
plt.errorbar(x3, y3, dy3, fmt='+', color='orangered', label='Data light level too hight')
plt.plot(lin, spline3(lin), color='salmon', label='light level too hight')
#plt.errorbar(xesc, yesc, dyesc, fmt='+', color='Green', label='Masked values' )
#plt.plot(lin, fit_model(lin, m, q), color='Red', label='Fit' )
plt.legend()
plt.grid(True)
plt.show()

plt.figure('Curva I-V polarizzazione inversa con Fit quadratico')
plt.title('Curva I-V polarizzazione inversa con fit quadratico')
plt.xlabel('Tensione di alimentazione SiPM [V]')
plt.ylabel('Corrent [nA]')
plt.yscale('log')
#lin=numpy.linspace(0, 100, 10000)
lin1 = numpy.linspace(numpy.min(x_fit1)-1, numpy.max(x_fit1), 1000)
plt.errorbar(x_fit1, y_fit1, dy_fit1, fmt='+', color='Blue', label='Data Dark')
plt.errorbar(x_masked1, y_masked1, dy_masked1, fmt='+', color='lightsteelblue', label='Data Dark Masked')
plt.plot(lin1, parabola(lin1, *popt1), color='cornflowerblue', label='Fit Dark')
lin2 = numpy.linspace(numpy.min(x_fit2)-1, numpy.max(x_fit2), 1000)
plt.errorbar(x_fit2, y_fit2, dy_fit2, fmt='+', color='Green', label='Data good light level')
plt.errorbar(x_masked2, y_masked2, dy_masked2, fmt='+', color='springgreen', label='Data good light level Masked')
plt.plot(lin2, parabola(lin2, *popt2), color='limegreen', label='Fit good light level')
lin3 = numpy.linspace(numpy.min(x_fit3)-1, numpy.max(x_fit3), 1000)
plt.errorbar(x_fit3, y_fit3, dy_fit3, fmt='+', color='orangered', label='Data light level too hight')
plt.errorbar(x_masked3, y_masked3, dy_masked3, fmt='+', color='lightsalmon', label='Data light level too hight Masked')
plt.plot(lin3, parabola(lin3, *popt3), color='coral', label='Fit light level too hight')


plt.legend()
plt.grid(True)
plt.show()

#Zeri delle parabole fittate
#Zero 1
camp=numpy.linspace(-100,100, 100000)
y1=parabola(camp, *popt1)
min1=numpy.min(y1)
print(f'il minimo della parabola 1 è={min1}')
c1_zero=c1-min1 #sto prendendo il minimo della parabola di fit per trovare il punto di breakdown perchè non passa da zero
zero1= (-b1 + numpy.sqrt(b1*b1 - 4*a1*c1_zero))/(2*a1)

#zero 2
camp=numpy.linspace(-100,100, 100000)
y2=parabola(camp, *popt2)
min2=numpy.min(y2)
print(f'il minimo della parabola 2 è={min2}')
c2_zero=c2-0 #sto prendendo lo zero della parabola di fit per trovare il punto di breakdown perchè passano da zero
zero2= (-b2 + numpy.sqrt(b2*b2 - 4*a2*c2_zero))/(2*a2)

#zero 3
camp=numpy.linspace(-100,100, 100000)
y3=parabola(camp, *popt3)
min3=numpy.min(y3)
print(f'il minimo della parabola 3 è={min3}')
c3_zero=c3-0 #sto prendendo lo zero della parabola di fit per trovare il punto di breakdown perchè passano da zero
zero3= (-b3 + numpy.sqrt(b3*b3 - 4*a3*c3_zero))/(2*a3)

#Calcolo dell'errore --> PROBLEMA NELLA PROPAGAZIONE DELL'ERRORE C'è DA CONSIDERARE LA CROSS CORRELAZIONE
#E CONTROLLARE LE FORMULE DI PROPAGAZIONE
SIGMA_a1= (numpy.absolute( ( (2*c1_zero)*(b1*b1 - 4*a1*c1_zero)**(-1/2) + (b1+ numpy.sqrt(b1*b1 - 4*a1*c1_zero)))/(4*a1*a1)))*sigma_a1
SIGMA_b1= (numpy.absolute((-1-(0.5)*(2*b1)*((b1*b1 - 4*a1*c1_zero)**(-1/2)))/(2*a1)))*sigma_b1
SIGMA_c1= (numpy.absolute( (2*a1*((b1*b1 - 4*a1*c1_zero)**(-1/2)))/ (2*a1)))*sigma_c1

print(SIGMA_a1)
print(SIGMA_b1)
print(SIGMA_c1)

d_zero1= numpy.sqrt(SIGMA_a1**2 + SIGMA_b1**2 + SIGMA_c1**2)
#d_zero2= numpy.sqrt(SIGMA_a2**2 + SIGMA_b2**2 + SIGMA_c2**2)
#d_zero3= numpy.sqrt(SIGMA_a3**2 + SIGMA_b3**2 + SIGMA_c3**2)

print(f'V_break1 = {zero1:.2f} +- {d_zero1:.2f}  V')
print(f'V_break2 = {zero2:.2f} +- {d_zero1:.2f}  V') #DA cambiare
print(f'V_break3 = {zero3:.2f} +- {d_zero1:.2f}  V') #DA cambiare
