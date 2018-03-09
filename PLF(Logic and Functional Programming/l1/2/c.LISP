(defun mini(l )
  (cond
    (
      (null (cdr l))
      (car l)
    )
    (
      (< (car l) (mini (cdr l)))
      (car l)
    )
    (
      t
      ;(> (car l) (mini (cdr l)))
      (mini (cdr l))
    )
  )
)

(defun removeOne(l e)
  (cond
    (
      (null l)
      nil
    )
    (
      (eq (car l) e) 
      (removeOne (cdr l) e )
    )
    (
      t
      (cons (car l) (removeOne (cdr l) e ))
    )
  )
)

(defun sortare(l)
  (cond
    (
      (null l)
       nil
    )
    (
      t
      (cons (mini l) (sortare (removeOne l (mini l)) ))
    )
  )
)

(print (sortare '(5 7 4 3 2 6 3 0 9 2 )))
