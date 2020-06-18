#!/usr/bin/env python

import numpy as np
from scipy.optimize import fsolve


# Inputs:
n=4; a=3e-9; q=1.0; k=1/16; T=1.0


# function definition:
def f(p):
    V1, V2, V3 = p
    return np.array([0.2*V1-0.2*V2-3, -0.2*V1+0.4*V2+a*np.exp(q*V2/(n*k*T)-1)-0.2*V3,-0.2*V2+0.3*V3])


# Stored the solutions:
V1, V2, V3 = fsolve(f,(15,6,5))


# Print solutions and error
l2_norm = np.linalg.norm(f((V1, V2, V3)))
print(f"V1 = {V1}, V2={V2}, V3={V3}, error_norm={l2_norm}")

#V1 = 20.398865279893535, V2=5.398865279893534, V3=3.5992435199290225, error_norm=6.661338147750939e-16







