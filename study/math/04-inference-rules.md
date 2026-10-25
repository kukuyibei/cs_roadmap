1. 推理规则（Rules of Inference）

有了命题和联结词，我们可以制定“推导规则”。最核心的有几个：

① 假言推理 (Modus Ponens)

    前提：p→qp→q 且 pp

    结论：qq

    翻译成 C 代码：if (p) { q }，如果 p 为真，那么 q 必然被执行（为真）。

② 拒取式 (Modus Tollens)

    前提：p→qp→q 且 ¬q¬q

    结论：¬p¬p

    解释：如果下雨（pp）则地湿（qq）。现在地没湿（¬q¬q），说明肯定没下雨（¬p¬p）。

③ 假言三段论 (Hypothetical Syllogism)

    前提：p→qp→q 且 q→rq→r

    结论：p→rp→r

    解释：传递性。

④ 析取三段论 (Disjunctive Syllogism)

    前提：p∨qp∨q 且 ¬p¬p

    结论：qq

    解释：要么 A 要么 B。现在排除了 A，那肯定是 B。

2. 形式证明的方法

形式证明就是列一个表：

    步骤 (Step)：写当前的命题。

    理由 (Reason)：说明这一步是用哪条规则、从哪一步推导出来的。

例题：
已知前提：

    p→qp→q

    q→rq→r

    ¬r¬r
    证明：¬p¬p