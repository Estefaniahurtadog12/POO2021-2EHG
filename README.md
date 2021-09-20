# Proyecto1-IsaacEscobar-StefaniaHurtado
# Sistema de calificaciones  📔 ✔️

## :heavy_check_mark: Objetivos 
- Identificar las clases principales
- Entender diagrama de usos 
- Desarrollar un programa orientado a objetos a partir de unos requerimientos específicos
- Crear un acta donde esta tenga criterios calificable
- Crear una clase que desde ahí me permita calificar dichos criterios 
- Crear clases necesarias para satisfacer requerimientos para el funcionario de la universidad
- Generar reportes 

## Enunciado 🗒️
-La dirección de los posgrados en ingeniería de software de la Pontificia Universidad Javeriana Cali quiere hacer un
sistema de información que facilite la calificación de los trabajos de grado de maestría cuando los estudiantes realizan
su sustentación pública. La directora espera que el sistema entregue un archivo de texto con los resultados de la
calificación obtenida por el estudiante y los comentarios relacionados con la evaluación. Esta evaluación se registra
en un acta de evaluación que es diligenciada normalmente durante una sesión de discusión luego de la sustentación y está compuesta por:

## FUNCIONES,CLASES Y ATRIBUTOS RELACIONADOS CON ACTAS 🗒️
- ACTA 💻. Contiene Número, fecha, autor, nombre del trabajo, tipo de trabajo ( 1. Aplicado, 2. Investigación ), director,
codirector (algunas veces existe un codirector), jurado 1, jurado 2.
- CRITERIO DE EVALUACION 🖥️. Actualmente son 8 criterios de evaluación pero podrían extenderse en el futuro.
Cada criterio tiene un identificador, un texto que es el texto que se presenta a los evaluadores y un
porcentaje de ponderación. El porcentaje de ponderación está definido por la dirección de los posgrados.
Eventualmente podría ser ajustados por la dirección de los posgrados.
- ACTA 💻. para cada criterio de evaluación se incluye la calificación del jurado número 1 y la calificación del
jurado número dos y los comentarios específicos para el criterio.
- ACTA 💻. permite incluir observaciones adicionales y comentarios específicos sobre las condiciones para la
aprobación del trabajo final.

## FUNCIONES, CLASES Y ATRIBUTOS RELACIONADOS CON ASISTENTE 🧑‍🤝‍🧑
- ASISTENTE DE MAESTRÍA 🖱️.  crea una nueva acta: Esta acta tiene la información de la fecha, el número
del acta, nombre del estudiante, nombre del trabajo, tipo de trabajo (investigación o aplicado), nombre director,
nombre codirector (si existe), nombre jurado 1 y nombre jurado 2. Yo soy la encarga de crear el acta para que
los jurados puedan posteriormente hacer la evaluación.

## FUNCIONES, CLASES Y ATRIBUTOS RELACIONADOS CON JURADO 👨‍⚖️
- JURADO DE MAESTRÍA 👩‍⚖️. Hace la evaluación de una tesis de maestría. La
información de la evaluación quedará registrada en un acta de evaluación creada previamente
en el sistema por la asistente de maestría. 
- NOTA:📔 Un mismo jurado es el encargado de ingresar
al sistema la calificación dada por el jurado uno y por el jurado dos. Adicionalmente él es
encargado de escribir las observaciones para cada criterio de evaluación y las observaciones
generales del trabajo.
- JURADO DE MAESTRÍA 👩‍⚖️. Quiero saber la nota final del trabajo de grado para cada acta, una
vez haya asignado una calificación para todos los criterios. Según la calificación el trabajo de
grado puede quedar: aprobado o rechazado. La nota final corresponde al promedio de las
calificaciones de cada criterio multiplicado por su porcentaje de ponderación. Con una nota
superior a 3.5 el trabajo de grado es aprobado. De lo contrario el trabajo de grado es
reprobado.}
- JURADO DE MAESTRÍA 👩‍⚖️.Quiero exportar la información del acta en un archivo de texto
una vez haya calculado la nota final.

## FUNCIONES, CLASES Y ATRIBUTOS RELACIONADOS CON DIRECTOR 🗒️
- DIRECTORA DE POSGRADOS ⏫. Quiero modificar la descripción o el peso de
los criterios de evaluación que se tienen en cuenta para elaborar las actas.
- DIRECTORA DE POSGRADOS ⏫.Quiero ver el número del
acta, la fecha, el nombre del estudiante, el estado, la nota, nombre de los jurados y director.
A fin de mantener las estadísticas disponibles aunque el sistema se cierre y se vuelva abrir, el sistema debe
mantener en un archivo de texto.
