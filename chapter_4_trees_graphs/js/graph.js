class Graph {
  /* Graph constructor */
  constructor(edgeDirection = Graph.DIRECTED) {
    this.nodes = {}
  }

  /* Adds a new vertex to graph, or return existing one */
  addVertex(value) {
    if (this.nodes[value]) {
      return this.nodes[value]
    } else {
      const node = new Node(value)
      this.nodes[value] = node
      return node
    }
  }

  /* Removes vertex from graph */
  removeVertex(value) {
    const current = this.nodes[value]
    if (current) {
      /* Removes edges connected to vertex */
      for (const node of Object.values(this.nodes)) {
        node.removeAdjacent(current)
      }
    }
    delete this.nodes[value]
    return current
  }

  /* Adds an edge between two vertexes */
  addEdge(source, destination) {
    const sourceNode = this.addVertex(source)
    const destinationNode = this.addVertex(destination)

    sourceNode.addAdjacent(destinationNode)
    /* bi-directional graphs */
    if (this.edgeDirection === Graph.UNDIRECTED) {
      destinationNode.addAdjacent(sourceNode)
    }

    return [sourceNode, destinationNode]
  }

  /* Removes an edge between two vertexes */
  removeEdge(source, destination) {
    const sourceNode = this.nodes[source]
    const destinationNode = this.nodes[destination]

    if (sourceNode && destinationNode) {
      sourceNode.removeAdjacent(destinationNode)
    }

    if (this.edgeDirection === Graph.UNDIRECTED) {
      destinationNode.removeAdjacent(sourceNode)
    }

    return [sourceNode, destinationNode]
  }
}

class GraphNode {
  /* Node constructor */
  constructor(value) {
    this.value = value
    this.adjacents = []
  }

  /* Adds an adjacent node */
  addAdjacent(node) {
    this.adjacents.push(node)
  }

  /* Removes an adjacent node */
  removeAdjacent(node) {
    const index = this.adjacents.indexOf(node)
    if (index > -1) this.adjacents.splice(index, 1)
  }
}

module.exports = {
  Graph,
  GraphNode
}
