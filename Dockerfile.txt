# Etapa 1:
FROM gcc:12 AS builder
WORKDIR /app
COPY Random.cpp .
RUN g++ -o random_app Random.cpp -static

# Etapa 2:
FROM scratch
COPY --from=builder /app/random_app /random_app
CMD ["/random_app"]
