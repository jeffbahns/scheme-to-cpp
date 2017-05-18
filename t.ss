
(define (literal_ident_return return_me_please)
  return_me_please
  )

(define (literal_quotedlit_return)
  6
  )

(define (returns_number)
  666
  )

(define (opraw t)
  (display t)
)

(define (cons_test t)
  (cons t t)
  )

(define (predicate_test t)
  (if (null? t)
      (zero? t)
      (if (char? t)
	  (string? t)
	  (symbol? t)
	  )
      )
  )

(define (not_test t)
  (if (not (null? t))
      (not (char? t))
      (not (list? t))
      )
  )

(define (add_test)
  (+ 5 6)
  )

(define (main)
  (display (not_test 5))
  (display (add_test))
  )
