(use '[clojure.string :only (split trim)])

; https://www.hackerrank.com/challenges/service-lane/problem
;
; Execute using `clojure servicelane.clj`.

(defn read-int
  "Read a single integer from STDIN"
  []
  (Integer/parseInt (trim (read-line))))

(defn read-ints
  "Read a list of ints from a line of input"
  []
  (map #(Integer/parseInt %) (split (trim (read-line)) #"\s+")))

(defn max-vehicle-size
  "Maximum-allowed vehicle width.
  Calculate the maximum width a vehicle can have
  to safely pass from `entry` to `exit`."
  [lane-widths entry exit]
  (->> lane-widths
       (drop entry)
       (take (inc (- exit entry)))
       (apply min)))

(let [[number-of-measurements number-of-test-cases] (read-ints)
      widths (read-ints)]
  (doall (for [i (range number-of-test-cases)]
           (let [[entry exit] (read-ints)]
             (println (max-vehicle-size widths entry exit))))))
