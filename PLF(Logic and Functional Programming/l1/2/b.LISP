(defun depth(l)
  (cond
    (
      (null l)
      0
    )
    (
      (atom (car l))
      (depth (cdr l))
    )
    (
      t
      (+ 1 (max (depth (car l)) (depth (cdr l))))
    )
  )
)

(print (+ 1 (depth '(1 2 (3 (4 (5))) (6 7)))))
(print (depth '(1 2 3 4)))