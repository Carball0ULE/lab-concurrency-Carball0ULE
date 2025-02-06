# Lab DPS - Práctica de Concurrencia
En esta práctica, exploramos una regla de concurrencia dada y explicamos una solución non-compliant y compliant con la regla dada por el SEI CERT.

La regla explorada es la siguiente: **CON40-C. Do not refer to an atomic variable twice in an expression**.

La solución compliant también hace referencia a **CON41-C. Wrap functions that can fail spuriously in a loop**.

Se incluye un **vídeo con la explicación de esta práctica** en el siguiente enlace:

https://drive.google.com/file/d/1IqMj03LvOjVhbvsY5r0KvPvpn-VUx6JW/view?usp=sharing

**OJO!**: Solo visible para miembros de la comunidad universitaria de la Universidad de León, asegúrate de **-iniciar sesión con una cuenta de Unileon para poder verlo-**.

Cualquier problema para acceder al recurso puedes reportármelo en el siguiente correo: acarbc01@estudiantes.unileon.es



## Referencias útiles para esta práctica
Regla SEI CERT CON40-C: https://wiki.sei.cmu.edu/confluence/display/c/CON40-C.+Do+not+refer+to+an+atomic+variable+twice+in+an+expression
Función atomic_compare_exchange_weak: https://en.cppreference.com/w/c/atomic/atomic_compare_exchange
Solución también compliant con CON41-C: https://wiki.sei.cmu.edu/confluence/display/c/CON41-C.+Wrap+functions+that+can+fail+spuriously+in+a+loop
Vulnberabilidad que referencia a CON40-C: https://cwe.mitre.org/data/definitions/366.html
