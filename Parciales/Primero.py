#!/usr/bin/env python3
#calculadora de  sueldo
"""
Este es un programa que calcula el sueldo que se
 debe pagar a un trabajador incluyendo horas extras
Programado por:
  Estudiante: Erick Liendo
  Cedula: 28672155
  III semestre ing. sistemas
   Universidad Experimental Politecnica de la fuerza Armada
   Nacional Bolivariana.
   prof: Edmundo Guiliani
"""

# Proceso salida
print("Introduzca datos del trabajador a calcular el sueldo neto")
# Proceso de obtencion de datos
nombre = str(input("Nombre: "))
apellido = str(input("Apellido: "))
cedula = str(input("Cedula: "))
sueldo = int(input("Sueldo mensual: "))

print("introdusca las horas extras trabajadas\n(introduzca 0 si no trabajo horas extra)")
horas_diurnas = int(input("diurno: "))
horas_nocturnas = int(input("nocturno: "))

sueldo_quincenal = sueldo/2
sobretiempo_diurno = sueldo_quincenal*horas_diurnas*0.4
sobretiempo_nocturno = sueldo_quincenal*horas_nocturnas*0.6
sueldo_neto = sueldo_quincenal+sobretiempo_diurno+sobretiempo_nocturno

print("\n"*3,
f"Nombre: {nombre}",
f"\nSueldo quincenal: {sueldo_quincenal}",
f"\nSobre tiempo diurno: {horas_diurnas}h = {sobretiempo_diurno}bs",
f"\nSobre tiempo nocturno: {horas_nocturnas} = {sobretiempo_nocturno}bs",
f"\nSueldo neto: {sueldo_neto}")


