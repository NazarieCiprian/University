(defun reversel(l)
  (cond
    (
      (null l)
      nil
    )
    (
      (atom (car l))
      (append (reversel (cdr l)) (list (car l)))
    )
    (
      t
      (append (reversel (cdr l)) (reversel (car l)))
    )
  )
)

(print (reversel '(((a b) c)(d e))))