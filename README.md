# magnet-automaton

## Summary

magnet-automaton is a simulation of a model of a magnet.  Physical justification TBC.

## Model used

The model we are using is a two-dimensional grid of 'cells'.  Each cell has a positive or negative polarity (or some other boolean physical property).  At certain times, a cell is chosen from this grid to be updated according to our update rule.  The update rule is as follows:

1. Let n be the number of 'orthogonal neighbours' (those directly north, east, south, west) to this cell.  Typically n = 4, but could be 2 or 3 for corners and edges respectively.

2. Let d be the number of differing polarities among the cell's neighbours.  So, for example, if a positive cell is surrounded entirely by negative cells, d = 4.

3. If d > n/2, flip the polarity of the cell.

## When to update

As of now, we will be running a model where a cell is selected at random from all of the cells in the grid and updated according to the above rule.  We are interested in both visualising the evolution of a randomly-initialised grid, and potentially statistically analysing its long-term behaviour.  A couple of examples of the latter: will grids always reach a 'stable' state, where no further updates can be made?  How many random updates will have to be done before such a stable state is achieved, as a function of grid size?  These questions should be easy to investigate with an efficient implementation of this model.

## Contributing

The project founders may contrbute (ideally addressing issues) by branching (typically from master) and making a pull request.  All other contributors will need to fork the repository and make a pull request from the fork.  This pull request MUST resolve an issue and be thoroughly reviewed before being merged in.
