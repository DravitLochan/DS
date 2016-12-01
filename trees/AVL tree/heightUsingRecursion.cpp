unsigned int depth(node *n)
{
    if (n == NULL)
        return 0;
    else
        return MAX(depth(n->left), depth(n->right)) + 1;
}
