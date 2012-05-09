(define (for-n start stop fn)
  (if (> start stop)
    '()
    (append
      (list (fn start))
      (for-n (+ start 1) stop fn)
    )
  )
)
