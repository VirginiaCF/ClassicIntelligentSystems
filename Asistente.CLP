; Mini Expert System to recommend art in auctions.
; Author: Virginia Corral
; Around 2021
; Created in CLIPS, the NASA code language for expert systems.

; Templates para los hechos
(deftemplate obra
  (slot nombre)
  (slot motivo)
  (slot estilo)
  (slot tecnica)
  (slot autor)
  (slot tonos)
  (slot fecha)
)
(deftemplate valor "Valor agregado encontrado"
  (slot nombre)
  (slot valor)
  (slot preferencia)
)
(deftemplate persona "Porcentajes de gusto"
  (slot paisaje)
  (slot objetos)
  (slot retratos)
  (slot abstracto)
)


; Hechos iniciales
(deffacts famosos
  (famoso Da_Vinci)
  (famoso Miguel_Angel)
  (famoso Rafael)
  (famoso Rembrandt)
  (famoso Dali)
)
(deffacts tecnicas "Multiplicador de precio por tecnica"
  (tecnica oleo 5)
  (tecnica acuarela 3)
  (tecnica mixta 1.5)
  (tecnica pastel 2)
  (tecnica carbon 2)
  (tecnica lapiz 1)
  (tecnica acrilico 2)
)
(deffacts temas "Multiplicador de precio por tematica"
  (tema historico 5)
  (tema bodegon 3)
  (tema paisaje 4)
  (tema arquitectonico 4)
  (tema retrato 2)
  (tema fantasia 2)
  (tema cotidiano 4)
)
(deffacts fechas "Multiplicador de precio por decadas"
  (fechas 1500 4)
  (fechas 1600 5)
  (fechas 1700 4)
  (fechas 1800 3)
  (fechas 1900 2)
  (fechas 2000 1)
)
(deffacts inicio
  (etapa inicio)
)

; Interfece de usuario cliente
(defrule inicio_bienvenida
  ?ini<-(etapa inicio)
=>
  (printout t crlf "   Este es tu Asistente de Subasta" crlf)
  (printout t crlf "Introduccion de tu perfil personal" crlf)
  (printout t "En escala de 1 a 10, Cuanto aprecias la naturaleza y la pintura natural?  ")
  (assert (perfil natural (read)))
  (printout t "En escala de 1 a 10, Cuanto te gustan los objetos decorativos y juegos de luz y sombra?  ")
  (assert (perfil decoracion (read)))
  (printout t "En escala de 1 a 10, Cuanto admiras un retrato?  ")
  (assert (perfil retrato (read)))
  (printout t "En escala de 1 a 10, Cuanto te inclinas por lo moderno, las formas y colores sin definicion exacta?  ")
  (assert (perfil abstracto (read)))
  (retract ?ini)
  (assert (etapa perfil))
)


; Razonamiento
  ;;Regla para obtener el perfil inicial
(defrule perfil
  (perfil natural ?natur)
  (perfil decoracion ?decor)
  (perfil retrato ?retra)
  (perfil abstracto ?abstr)
  ?per <- (etapa perfil)
=>
  (bind ?tot (+ ?natur ?decor ?retra ?abstr))
  (bind ?natural (/ (* ?natur 100) ?tot))
  (bind ?decoracion (/ (* ?decor 100) ?tot))
  (bind ?retrato (/ (* ?retra 100) ?tot))
  (bind ?abstracto (/ (* ?abstr 100) ?tot))
  (assert (persona (paisaje ?natural)(objetos ?decoracion)(retratos ?retrato)(abstracto ?abstracto)))
  (assert (explica obtencion perfil))
)
  

; Explicacion
  ;;Regla que explica como se obtuvo el perfil personal
(defrule explica_perfil
  (etapa explicacion)
  (perfil natural ?natur)
  (perfil decoracion ?decor)
  (perfil retrato ?retra)
  (perfil abstracto ?abstr)
=>
  (printout t crlf "Explicacion del perfil personal encontrado" crlf)
  (printout t "El usuario introdujo los siguientes valores de preferencia:" crlf)
  (printout t "Califica el paisaje con un " ?natur crlf)
  (printout t "Califica el bodegon con un " ?decor crlf)
  (printout t "Califica el retrato con un " ?retra crlf)
  (printout t "Califica el arte abstracto con un " ?abstr crlf)
)