SELECT e.id_empleado, e.primerapellido, e.segundapellido , e.nombres 
FROM empleado e
INNER JOIN trabaja_en te
INNER JOIN proyecto p
INNER JOIN Departamento d
ON e.id_empleado = te.id_empleado
AND p.id_proyecto = te.id_proyecto
AND p.id_departamento = d.id_departamento
WHERE sexo = 'M' AND p.id_proyecto = 3
ORDER BY e.primer_apellido
