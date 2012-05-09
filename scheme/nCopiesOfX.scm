(define (nCopies n x)
  (if (> n 0)
    (append (list x) (nCopies (- n 1) x))
    '()
  )
)


