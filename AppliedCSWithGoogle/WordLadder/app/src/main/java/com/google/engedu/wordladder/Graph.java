package com.google.engedu.wordladder;

import java.util.*;

public class Graph {
    private HashMap<String, Vertex> vertices;
    private HashMap<Integer, Edge> edges;

    public Graph() {
        this.vertices = new HashMap<String, Vertex>();
        this.edges = new HashMap<Integer, Edge>();
    }

    public Graph(HashSet<Vertex> vertices) {
        this.vertices = new HashMap<String, Vertex>();
        this.edges = new HashMap<Integer, Edge>();
        for (Vertex vertex: vertices) {
            this.vertices.put(vertex.getLabel(), vertex);
        }
    }

    public boolean addEdge(Vertex one, Vertex two) {
        return addEdge(one, two, 1);
    }

    public boolean addEdge(Vertex one, Vertex two, int weight) {
        if (one.equals(two)) {
            return false;
        }
        Edge edge = new Edge(one, two, weight);
        if (edges.containsKey(edge.hashCode())) {
            return false;
        } else if (one.containsNeighbor(edge) || two.containsNeighbor(edge)) {
            return false;
        }
        edges.put(edge.hashCode(), edge);
        one.addNeighbor(edge);
        two.addNeighbor(edge);
        return true;
    }

    public boolean containsEdge(Edge edge) {
        if (edge.getOne() == null || edge.getTwo() == null) {
            return false;
        }
        return this.edges.containsKey(edge.hashCode());
    }

    public Edge removeEdge(Edge edge) {
        edge.getOne().removeNeighbor(edge);
        edge.getTwo().removeNeighbor(edge);
        return this.edges.remove(edge.hashCode());
    }

    public boolean containsVertex(Vertex vertex) {
        return this.vertices.get(vertex.getLabel()) != null;
    }

    public Vertex getVertex(String label) {
        return vertices.get(label);
    }

    public boolean addVertex(Vertex vertex, boolean overwriteExisting) {
        Vertex current = this.vertices.get(vertex.getLabel());
        if (current != null) {
            if (!overwriteExisting) {
                return false;
            }
            while (current.getNeighborCount() > 0) {
                this.removeEdge(current.getNeighbor(0));
            }
        }
        vertices.put(vertex.getLabel(), vertex);
        return true;
    }

    public Vertex removeVertex(String label) {
        Vertex vertex = vertices.remove(label);
        while(vertex.getNeighborCount() > 0) {
            this.removeEdge(vertex.getNeighbor(0));
        }
        return vertex;
    }

    public Set<String> vertexKeys() {
        return this.vertices.keySet();
    }

    public Set<Edge> getEdges() {
        return new HashSet<Edge>(this.edges.values());
    }
}
