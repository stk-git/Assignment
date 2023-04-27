# Assignment
Hyderabad consists of numerous network towers of various network providers. The metadata
consisting of the location of the towers is given to you in an array format towers, where towers[i] =
[xi, yi, qi] denotes the ith network tower with location (xi, yi) and quality factor qi. All the coordinates
are integral coordinates on the X-Y plane, and the distance between the two coordinates is the
Euclidean distance.

You are also given an integer radius where a tower is reachable if the distance is less than or
equal to radius. Outside that distance, the signal becomes garbled, and the tower is not reachable.

The signal quality of the ith tower at a coordinate (x, y) is calculated with the formula ⌊qi / (1 + d)⌋,
where d is the distance between the tower and the coordinate. The network quality at a coordinate
is the sum of the signal qualities from all the reachable towers.

Return the array [cx, cy] representing the integral coordinate (cx, cy) where the network quality is
maximum. If there are multiple coordinates with the same network quality, return the
lexicographically minimum non-negative coordinate.
