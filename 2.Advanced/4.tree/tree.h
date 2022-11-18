///
/// tree.h
///

#pragma once

#include <cstdio>

template <typename T>
class Tree {

  struct Node {

    Node(T value)
    : value_(value), left_(), right_()
    {}

    ~Node() noexcept
    {}

    bool in(T value) const {
      if (this == nullptr) {
        return false;
      }
      if (value < value_) {
        return left_->in(value);
      }
      if (value_ < value) {
        return right_->in(value);
      }
      return true;
    }

    void *add(T value) {
      Node *node = this;
      for (;;) {
        if (value < node->value_) {
          if (node->left_ == nullptr) {
            node->left_ = new Node(value);
            break;
          } else {
            node = node->left_;
            continue;
          }
        }
        if (node->value_ < value) {
          if (node->right_ == nullptr) {
            node->right_ = new Node(value);
            break;
          } else {
            node = node->right_;
            continue;
          }
        }
        break; // already in the tree: do not add
      }
    }

    int min_depth() const {
      if (this == nullptr) {
        return 0;
      }
      int ld = left_->min_depth();
      int rd = right_->min_depth();
      return 1 + (ld < rd ? ld : rd);
    }

    int max_depth() const {
      if (this == nullptr) {
        return 0;
      }
      int ld = left_->max_depth();
      int rd = right_->max_depth();
      return 1 + (ld < rd ? rd : ld);
    }

    void show(FILE *output, int depth) const {
    }

    T value_;
    Node *left_;
    Node *right_;
  };

public:

  Tree()
  : root_(nullptr)
  {}

  Tree(T value)
  : root_(new Node(value))
  {}

  ~Tree() noexcept {
    reset();
  }

  bool empty() const {
    return root_ == nullptr;
  }

  bool in(T value) const {
    if (empty()) {
      return false;
    }
    return root_->in(value);
  }

  void add(T value) {
    if (root_ == nullptr) {
      root_ = new Node(value);
    } else {
      root_->add(value);
    }
  }

  void show(FILE *output) const {
    if (empty()) {
      fprintf(output, "{}");
    } else {
      root_->show(output, 0);
    }
  }

  int min_depth() const {
    return root_->min_depth();
  }

  int max_depth() const {
    return root_->max_depth();
  }

private:

  void reset() noexcept {
    delete root_;
    root_ = nullptr;
  }

  Node *root_;
};
