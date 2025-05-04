#/usr/bin/env python3
# -*- coding: UTF-8 -*- 
# TAREA DE PROGRAMACION
# app que calcula el area de 13 figuras geometricas
# Erick Liendo

from math import pi, radians, sqrt, tan as tag
from sys import exit as salir
from os import system

def limpiar():
    system('clear')
class Crear_Figura:
    figuras = {
            1 : 'circulo',
            3 : 'triangulo',
            4 : 'cuadrilatero',
            5 : 'pentagono',
    }
    def __init__(self, *lados):
        if type(lados[0]) == tuple: lados = lados[0]
        # Lados : recibe el conjuto de longitudes que
        #componen una figura geometrica. En caso de
        #ser un circulo recibe el radio.
        self.datos ={}
        tipo = self.figuras[len(lados)]
        self.datos["tipo"] = tipo
        if tipo == 'circulo':
        # Toma el argumento lados, como radio
            self.datos["radio"] = lados[0]
            self.datos["diametro"] = 2*lados[0]
            self.datos["longitud"] = 2*lados[0]*pi
            self.datos["area"] = pi * (lados[0]**2)
            return
        perimetro = 0
        for r in lados:
            perimetro+=r
        self.datos['perimetro'] = perimetro
        if tipo == 'triangulo':
            a, b, c = lados[0], lados[1], lados[2]
            s = (a+b+c)/2
            self.datos['area'] = sqrt(s*((s-a)*(s-b)*(s-c)))
            self.datos['altura'] = 2*self.datos['area']/b
        elif tipo == 'cuadrilatero':
            pass
        elif tipo == 'pentagono':
            pass

class App():
    configuración = {
        'mini_ui' : True,
        'area ': True,
        'diametro' : True,
        'apotema' : True,
        'angulos' : False,
    }
    def __init__(self):
        print("HERRAMIENTA GEOMETRICA")
        while True:
            self.__interfas_de_usuario__()
    def __interfas_de_usuario__(self):
        opciones = {
            '$0' : 'cerrar\t\t(finalizar ejecución)',
            '$1' : 'comandos\t\t(lista de comandos)',
            '$2' : 'guia\t\t\t(instrucciones de uso)',
        }
        comandos = {
            '$lista' : '\t\tMuestra las figuras soportadas',
            '$area' : '\t\tMuestra solo el area',
            '$diametro' : '\tMuestra solo el diametro',
            '$apotema' : '\tMuestra solo el apotema',
            '$angulos' : '\tMuestra solo los grados de cada angulo',
            '$miniUI' : '\tOcultar/Motrar las instrucciones del inicio',
            '$restaurar' : '\trestaura a los valores por defecto',
            '$limpiar' : '\tLimpiar pantalla',
        }
        GUIA = '''
 Como su nombre indica esta herramienta permite
obtener(o calcular) datos de ciertas figuras geometricas,
solo con la longitud de sus lados.

 MODO DE USO
por defecto solo con colocar la logitud de cada lado
separado por espacios obtendra los datos de la figura,
al estar basado en poligono se detecta automsticamente
el tipo de figura que es.

EJEMPLO: 
    >>5
    salida:
        tipo: circulo
        radio: 5
        diametro: 10
        longitud: 31.4159
        area: 78.5398
    >>5 5 5 5
    salida:
        tipo: cuadrilatero
        perimetro: 20
        area: 25
'''
        if self.configuración['mini_ui']: self.__ver__(opciones)
        
        cmd = str(input('>>'))
        cmd, longitudes = self.__separar_datos__(cmd, [',',' '])

        if len(longitudes) >= 1:
            figura = Crear_Figura(tuple(longitudes))
            for r in figura.datos:
                print(f'{r} : {figura.datos[r]}')
        
        if '$1' in cmd: self.__ver__(comandos)
        if '$2' in cmd: print(GUIA)
        if '$lista' in cmd:
            print("FIGURAS SOPORTADAS:\n",
                "nro lados\t\tfigura")
            for r in Crear_Figura.figuras:
                print(f"\t{r} \t\t{Crear_Figura.figuras[r]}\n")
        if '$miniUI' in cmd:
            estado = self.configuración['mini_ui']
            if estado == True:
                self.configuración['mini_ui'] = False
            else: self.configuración['mini_ui'] = True
        if '$limpiar' in cmd: limpiar()
        if '$0' in cmd: salir()
        
    def __ver__(self, opcion):
        print('\nCOMANDO\t\t\tDESCRIPCIÓN')
        for r in opcion:
            print(r, opcion[r])
    def __separar_datos__(self, dato, separadores):
        datos, cmd, longitudes = [], [], []
        dato+=separadores[0]
        indice_i, indice_f = -1, 0
        for i in range(len(dato)):
            r = dato[i]
            if r in separadores:
                indice_f = i
                datos.append(dato[indice_i+1:indice_f])
                indice_i = i
        for i in range(len(datos)):
            try: longitudes.append(float(datos[i]))
            except: cmd.append(datos[i])
        return cmd, longitudes
if __name__ == '__main__':
    app = App()
