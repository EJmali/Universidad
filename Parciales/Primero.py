env python3

#APP: calculadora de sueldo
#Este programa muestra los datos de
#sueldo para un usuario.
"""
Desarrollador:
    Nombre:    Erick Liendo
    Cedula:      28672155
    Estudiante de la UNEFA

    Tarea:
    Crear un programa para calcular el sueldo de un usuario.
    Criterios a evaluar:
    identificacación: El programa debe estar identificado y 
    el programador tambien.

    descripcion: Se debe proporcionar una descripcion de lo
    que hace el programa
                                                                                                    
    Identificar procesos: identificar cada proceso
    de entrada y salida de datos.
                                                                                                                                                                                                                                                                                             
"""

# Proceso salida para informar al usuario sobre la recolección de datos
print("Introduzca datos del trabajador a calcular el sueldo neto")
# Proceso de obtencion de datos
nombre = str(input("Nombre completo: ")) #proceso de entrada: solicitud de nombre de usuario
cedula = str(input("Cedula: "))#proceso de entrada: solicitud de cedula del usuario
sueldo = int(input("Sueldo mensual: "))#proceso de entrada: solicitud de sueldo mensual

# Proceso de salida: Para informar al usuario la recoleccion de datos para las horas extra
print("introdusca las horas extras trabajadas\n(introduzca 0 si no trabajo horas extra)")
horas_diurnas = int(input("diurno: "))#proceso de entrada: solicitud de horas extras diurnas
horas_nocturnas = int(input("nocturno: "))#proceso de entrada: solicitud de hiras extras nocturnas

sueldo_quincenal = sueldo/2
sobretiempo_diurno = sueldo_quincenal*horas_diurnas*0.4
sobretiempo_nocturno = sueldo_quincenal*horas_nocturnas*0.6
sueldo_neto = sueldo_quincenal+sobretiempo_diurno+sobretiempo_nocturno

#Proceso de salida: para mostrar los datos solicitados por el usuario
print("\n"*3,
      f"El pago para el trabajador {nombre}:",
      f"\nportador de la cedula {cedula} es:",
      f"\nSueldo Mesual: {sueldo}",
      f"\nSueldo quincenal: {sueldo_quincenal}",
      f"\nSobre tiempo diurno: {horas_diurnas}h = {sobretiempo_diurno}bs",
      f"\nSobre tiempo nocturno: {horas_nocturnas} = {sobretiempo_nocturno}bs",
      f"\nSueldo neto: {sueldo_neto}")
