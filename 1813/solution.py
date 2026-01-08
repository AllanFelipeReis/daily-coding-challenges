class OrderLog:
    def __init__(self, n):
        self.n = n
        self.log = [None] * n
        self.current_index = 0

    def record(self, order_id):
        self.log[self.current_index] = order_id
        self.current_index = (self.current_index + 1) % self.n

    def get_last(self, i):
        return self.log[(self.current_index - i + self.n) % self.n]


# Inicialização
logger = OrderLog(3)

# Ações
logger.record("Order_1")
logger.record("Order_2")
logger.record("Order_3")
logger.record("Order_4")  # Aqui, Order_1 deve ser removido

# Verificação
print(logger.get_last(1))  # Esperado: "Order_4" (O último inserido)
print(logger.get_last(3))  # Esperado: "Order_2" (O 3º último, já que o 1 sumiu)


# Inicialização
logger = OrderLog(5)

# Ações
logger.record("Order_A")
logger.record("Order_B")

# Verificação
print(logger.get_last(1))  # Esperado: "Order_B" (OK)
print(logger.get_last(3))  # Resultado: None (ou erro, dependendo da linguagem)
