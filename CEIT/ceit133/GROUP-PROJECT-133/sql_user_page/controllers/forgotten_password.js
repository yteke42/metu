const db = require("../routes/db-config");
const bcrypt = require("bcryptjs");



form.addEventListener("submit", () => {
    const forgotten_password = {
        email: email.value,
        recoveryCode: recov.value,
        newPassword: newPassword.value
        
    }
    fetch("/api/register", {
        method: "POST",
        body: JSON.stringify(register),
        headers: {
            "Content-Type": "application/json"
        }
    }) .then(res => res.json())
            .then(data => {
                if(data.status == "error") {
                    success.style.display = "none"
                    error.style.display = "block"
                    error.innerText = data.error
                } else {
                    error.style.display = "none"
                    success.style.display = "block"
                    success.innerText = data.success
                }   
            })
        
})  




const forgotten_password = async (req, res) => {
    const {email, recov, password} = req.body;
    db.query("SELECT * FROM users WHERE email = ?"), [email], async (err, result) => {
        if (err) throw err;
        console.log(result)
    }
}