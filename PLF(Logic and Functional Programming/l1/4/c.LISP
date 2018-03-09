(defun reversea(l)
  (cond
   (
     (null l)
     nil
   )
   (
     (atom (car l))
     (append (reversea (cdr l)) (list (car l)))
   )
   (
     t
     (cons (reversea (car l)) (reversea (cdr l)))
   )
 )
)

(print (reversea '(a b c (d (e f) g h i))))