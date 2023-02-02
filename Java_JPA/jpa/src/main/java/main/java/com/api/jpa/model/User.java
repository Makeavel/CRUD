package main.java.com.api.jpa.model;

import java.util.UUID;

import jakarta.persistence.Column;
import jakarta.persistence.Id;
import jakarta.persistence.Table;
import lombok.Data;

@Data
@Table(name = "user")
public class User {
    
    @Id
    private UUID id;
    @Column(name = "cpf")
    private String cpf;
    @Column(name = "name")
    private String name;
}
