! function(e, t) {
    "object" == typeof exports && "object" == typeof module ? module.exports = t() : "function" == typeof define && define.amd ? define([], t) : "object" == typeof exports ? exports["my-library"] = t() : e["my-library"] = t()
}(self, (() => (() => {
    "use strict";
    var e = {};

    function t(e, t) {
        for (var a = 0; a < t.length; a++) {
            var n = t[a];
            n.enumerable = n.enumerable || !1, n.configurable = !0, "value" in n && (n.writable = !0), Object.defineProperty(e, n.key, n)
        }
    }(e => {
        "undefined" != typeof Symbol && Symbol.toStringTag && Object.defineProperty(e, Symbol.toStringTag, {
            value: "Module"
        }), Object.defineProperty(e, "__esModule", {
            value: !0
        })
    })(e);
    var a = function() {
        function e(t) {
            var a, n, l, s, i, r, d, c, o, h, v, u, y, g, m, M, p, b, f, w, _, D, T, Y, L, k, x, E, H, F, S, N, A, O, q, j, J, P, V, W, C, z, B, G, I, K, Q, R, U, X, Z, $, ee, te, ae, ne;
            ! function(e, t) {
                if (!(e instanceof t)) throw new TypeError("Cannot call a class as a function")
            }(this, e), this.HTMLElement = t.HTMLElement, this.type = null !== (a = t.type) && void 0 !== a ? a : "default", this.date = {
                min: null !== (n = null === (l = t.date) || void 0 === l ? void 0 : l.min) && void 0 !== n ? n : "1970-01-01",
                max: null !== (s = null === (i = t.date) || void 0 === i ? void 0 : i.max) && void 0 !== s ? s : "2470-12-31",
                today: null !== (r = null === (d = t.date) || void 0 === d ? void 0 : d.today) && void 0 !== r ? r : new Date
            }, this.settings = {
                lang: null !== (c = null === (o = t.settings) || void 0 === o ? void 0 : o.lang) && void 0 !== c ? c : "en",
                iso8601: null === (h = null === (v = t.settings) || void 0 === v ? void 0 : v.iso8601) || void 0 === h || h,
                range: {
                    min: null !== (u = null === (y = t.settings) || void 0 === y || null === (g = y.range) || void 0 === g ? void 0 : g.min) && void 0 !== u ? u : this.date.min,
                    max: null !== (m = null === (M = t.settings) || void 0 === M || null === (p = M.range) || void 0 === p ? void 0 : p.max) && void 0 !== m ? m : this.date.max,
                    disabled: null !== (b = null === (f = t.settings) || void 0 === f || null === (w = f.range) || void 0 === w ? void 0 : w.disabled) && void 0 !== b ? b : null
                },
                selection: {
                    day: null !== (_ = null === (D = t.settings) || void 0 === D || null === (T = D.selection) || void 0 === T ? void 0 : T.day) && void 0 !== _ ? _ : "single",
                    month: null === (Y = null === (L = t.settings) || void 0 === L || null === (k = L.selection) || void 0 === k ? void 0 : k.month) || void 0 === Y || Y,
                    year: null === (x = null === (E = t.settings) || void 0 === E || null === (H = E.selection) || void 0 === H ? void 0 : H.year) || void 0 === x || x
                },
                selected: {
                    dates: null !== (F = null === (S = t.settings) || void 0 === S || null === (N = S.selected) || void 0 === N ? void 0 : N.dates) && void 0 !== F ? F : null,
                    month: null !== (A = null === (O = t.settings) || void 0 === O || null === (q = O.selected) || void 0 === q ? void 0 : q.month) && void 0 !== A ? A : null,
                    year: null !== (j = null === (J = t.settings) || void 0 === J || null === (P = J.selected) || void 0 === P ? void 0 : P.year) && void 0 !== j ? j : null,
                    holidays: null !== (V = null === (W = t.settings) || void 0 === W || null === (C = W.selected) || void 0 === C ? void 0 : C.holidays) && void 0 !== V ? V : null
                },
                visibility: {
                    weekend: null === (z = null === (B = t.settings) || void 0 === B || null === (G = B.visibility) || void 0 === G ? void 0 : G.weekend) || void 0 === z || z,
                    today: null === (I = null === (K = t.settings) || void 0 === K || null === (Q = K.visibility) || void 0 === Q ? void 0 : Q.today) || void 0 === I || I,
                    disabled: null !== (R = null === (U = t.settings) || void 0 === U || null === (X = U.visibility) || void 0 === X ? void 0 : X.disabled) && void 0 !== R && R
                }
            }, this.actions = {
                clickDay: null !== (Z = null === ($ = t.actions) || void 0 === $ ? void 0 : $.clickDay) && void 0 !== Z ? Z : null,
                clickMonth: null !== (ee = null === (te = t.actions) || void 0 === te ? void 0 : te.clickMonth) && void 0 !== ee ? ee : null,
                clickYear: null !== (ae = null === (ne = t.actions) || void 0 === ne ? void 0 : ne.clickYear) && void 0 !== ae ? ae : null
            }, this.name = {
                months: {
                    full: {
                        en: ["January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"],
                        ru: ["Январь", "Февраль", "Март", "Апрель", "Май", "Июнь", "Июль", "Август", "Сентябрь", "Октябрь", "Ноябрь", "Декабрь"]
                    },
                    reduction: {
                        en: ["Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"],
                        ru: ["Янв", "Фев", "Мар", "Апр", "Май", "Июн", "Июл", "Авг", "Сен", "Окт", "Ноя", "Дек"]
                    }
                },
                week: {
                    en: ["Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"],
                    ru: ["Вс", "Пн", "Вт", "Ср", "Чт", "Пт", "Сб"]
                },
                arrow: {
                    prev: {
                        en: "Prev",
                        ru: "Назад"
                    },
                    next: {
                        en: "Next",
                        ru: "Вперед"
                    }
                }
            }, this.currentType = this.type
        }
        var a, n;
        return a = e, (n = [{
            key: "setVariablesDates",
            value: function() {
                this.selectedDates = [], this.selectedMonth = this.date.today.getMonth(), this.selectedYear = this.date.today.getFullYear(), null !== this.settings.selected.dates && (this.selectedDates = this.settings.selected.dates), null !== this.settings.selected.month && this.settings.selected.month >= 0 && this.settings.selected.month < 12 && (this.selectedMonth = this.settings.selected.month), null !== this.settings.selected.year && this.settings.selected.year >= 0 && this.settings.selected.year <= 9999 && (this.selectedYear = this.settings.selected.year), this.viewYear = this.selectedYear, this.dateMin = this.settings.visibility.disabled ? new Date(this.date.min) : new Date(this.settings.range.min), this.dateMax = this.settings.visibility.disabled ? new Date(this.date.max) : new Date(this.settings.range.max)
            }
        }, {
            key: "createDOM",
            value: function() {
                var e, t;
                if ("default" === this.currentType) this.HTMLElement.classList.add("vanilla-calendar_default"), this.HTMLElement.classList.remove("vanilla-calendar_month"), this.HTMLElement.classList.remove("vanilla-calendar_year"), this.HTMLElement.innerHTML = '\n\t\t\t<div class="vanilla-calendar-header">\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_prev">\n\t\t\t\t\t'.concat(null !== (e = this.name.arrow.prev[this.settings.lang]) && void 0 !== e ? e : this.name.arrow.prev.en, '\n\t\t\t\t</button>\n\t\t\t\t<div class="vanilla-calendar-header__content">\n\t\t\t\t\t<b class="vanilla-calendar-month').concat(this.settings.selection.month ? "" : " vanilla-calendar-month_disabled", '"></b>\n\t\t\t\t\t<b class="vanilla-calendar-year').concat(this.settings.selection.year ? "" : " vanilla-calendar-year_disabled", '"></b>\n\t\t\t\t</div>\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_next">\n\t\t\t\t\t').concat(null !== (t = this.name.arrow.next[this.settings.lang]) && void 0 !== t ? t : this.name.arrow.next.en, '\n\t\t\t\t</button>\n\t\t\t</div>\n\t\t\t<div class="vanilla-calendar-content">\n\t\t\t\t<div class="vanilla-calendar-week"></div>\n\t\t\t\t<div class="vanilla-calendar-days"></div>\n\t\t\t</div>\n\t\t');
                else if ("month" === this.currentType) {
                    var a, n;
                    this.HTMLElement.classList.remove("vanilla-calendar_default"), this.HTMLElement.classList.add("vanilla-calendar_month"), this.HTMLElement.classList.remove("vanilla-calendar_year"), this.HTMLElement.innerHTML = '\n\t\t\t<div class="vanilla-calendar-header">\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_prev"\n\t\t\t\t\tstyle="visibility: hidden">\n\t\t\t\t\t'.concat(null !== (a = this.name.arrow.prev[this.settings.lang]) && void 0 !== a ? a : this.name.arrow.prev.en, '\n\t\t\t\t</button>\n\t\t\t\t<div class="vanilla-calendar-header__content">\n\t\t\t\t\t<b class="vanilla-calendar-month"></b>\n\t\t\t\t\t<b class="vanilla-calendar-year vanilla-calendar-year_not-active').concat(this.settings.selection.year ? "" : " vanilla-calendar-year_disabled", '"></b>\n\t\t\t\t</div>\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_next"\n\t\t\t\t\tstyle="visibility: hidden">\n\t\t\t\t\t').concat(null !== (n = this.name.arrow.next[this.settings.lang]) && void 0 !== n ? n : this.name.arrow.next.en, '\n\t\t\t\t</button>\n\t\t\t</div>\n\t\t\t<div class="vanilla-calendar-content">\n\t\t\t\t<div class="vanilla-calendar-months"></div>\n\t\t\t</div>')
                } else if ("year" === this.currentType) {
                    var l, s;
                    this.HTMLElement.classList.remove("vanilla-calendar_default"), this.HTMLElement.classList.remove("vanilla-calendar_month"), this.HTMLElement.classList.add("vanilla-calendar_year"), this.HTMLElement.innerHTML = '\n\t\t\t<div class="vanilla-calendar-header">\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_prev">\n\t\t\t\t\t'.concat(null !== (l = this.name.arrow.prev[this.settings.lang]) && void 0 !== l ? l : this.name.arrow.prev.en, '\n\t\t\t\t</button>\n\t\t\t\t<div class="vanilla-calendar-header__content">\n\t\t\t\t\t<b class="vanilla-calendar-month vanilla-calendar-month_not-active').concat(this.settings.selection.month ? "" : " vanilla-calendar-month_disabled", '"></b>\n\t\t\t\t\t<b class="vanilla-calendar-year"></b>\n\t\t\t\t</div>\n\t\t\t\t<button type="button"\n\t\t\t\t\tclass="vanilla-calendar-arrow vanilla-calendar-arrow_next">\n\t\t\t\t\t').concat(null !== (s = this.name.arrow.next[this.settings.lang]) && void 0 !== s ? s : this.name.arrow.next.en, '\n\t\t\t\t</button>\n\t\t\t</div>\n\t\t\t<div class="vanilla-calendar-content">\n\t\t\t\t<div class="vanilla-calendar-years"></div>\n\t\t\t</div>')
                }
            }
        }, {
            key: "controlArrows",
            value: function() {
                var e = this;
                if (["default", "year"].includes(this.currentType)) {
                    var t = this.HTMLElement.querySelector(".vanilla-calendar-arrow_prev"),
                        a = this.HTMLElement.querySelector(".vanilla-calendar-arrow_next");
                    ! function() {
                        if ("default" === e.currentType) {
                            var n = e.selectedMonth === e.dateMin.getMonth(),
                                l = e.selectedMonth === e.dateMax.getMonth(),
                                s = e.selectedYear === e.dateMin.getFullYear(),
                                i = e.selectedYear === e.dateMax.getFullYear();
                            n && s || !e.settings.selection.month ? t.style.visibility = "hidden" : t.style.visibility = null, l && i || !e.settings.selection.month ? a.style.visibility = "hidden" : a.style.visibility = null
                        }
                    }(), "year" === e.currentType && (e.dateMin.getFullYear() && e.viewYear - 7 <= e.dateMin.getFullYear() ? t.style.visibility = "hidden" : t.style.visibility = null, e.dateMax.getFullYear() && e.viewYear + 7 >= e.dateMax.getFullYear() ? a.style.visibility = "hidden" : a.style.visibility = null)
                }
            }
        }, {
            key: "writeYear",
            value: function() {
                this.HTMLElement.querySelector(".vanilla-calendar-year").innerText = this.selectedYear
            }
        }, {
            key: "writeMonth",
            value: function() {
                this.HTMLElement.querySelector(".vanilla-calendar-month").innerText = this.name.months.full[this.settings.lang][this.selectedMonth]
            }
        }, {
            key: "createWeek",
            value: function() {
                var e = this.HTMLElement.querySelector(".vanilla-calendar-week"),
                    t = this.name.week[this.settings.lang];
                this.settings.iso8601 && t.push(t.shift());
                for (var a = 0; a < t.length; a++) {
                    var n = t[a],
                        l = document.createElement("span");
                    l.className = "vanilla-calendar-week__day", this.settings.visibility.weekend && this.settings.iso8601 ? 5 !== a && 6 !== a || l.classList.add("vanilla-calendar-week__day_weekend") : this.settings.visibility.weekend && !this.settings.iso8601 && (0 !== a && 6 !== a || l.classList.add("vanilla-calendar-week__day_weekend")), l.innerText = "".concat(n), e.append(l)
                }
            }
        }, {
            key: "createDays",
            value: function() {
                var e = this,
                    t = new Date(this.selectedYear, this.selectedMonth, 1),
                    a = new Date(this.selectedYear, this.selectedMonth + 1, 0).getDate(),
                    n = Number(t.getDay());
                this.settings.iso8601 && (n = Number((0 !== t.getDay() ? t.getDay() : 7) - 1));
                var l = this.HTMLElement.querySelector(".vanilla-calendar-days");
                ["single", "multiple", "multiple-ranged"].includes(this.settings.selection.day) && l.classList.add("vanilla-calendar-days_selecting"), l.innerHTML = "";
                var s = function(t, a, n) {
                    !e.settings.visibility.weekend || 0 !== a && 6 !== a || t.classList.add("vanilla-calendar-day_weekend"), Array.isArray(e.settings.selected.holidays) && e.settings.selected.holidays.forEach((function(e) {
                        e === n && t.classList.add("vanilla-calendar-day_holiday")
                    }));
                    var l = e.date.today.getDate();
                    l = l < 10 ? "0".concat(l) : l;
                    var s = e.date.today.getMonth() + 1;
                    s = s < 10 ? "0".concat(s) : s;
                    var i = "".concat(e.date.today.getFullYear(), "-").concat(s, "-").concat(l);
                    e.settings.visibility.today && t.dataset.calendarDay === i && t.classList.add("vanilla-calendar-day_today"), e.selectedDates.find((function(e) {
                        return e === n
                    })) && t.classList.add("vanilla-calendar-day_selected"), (e.settings.range.min > n || e.settings.range.max < n) && t.classList.add("vanilla-calendar-day_disabled"), Array.isArray(e.settings.range.disabled) && e.settings.range.disabled.forEach((function(e) {
                        e === n && t.classList.add("vanilla-calendar-day_disabled")
                    }))
                };
                ! function() {
                    var t = new Date(e.selectedYear, e.selectedMonth, 0).getDate() - n,
                        a = e.selectedYear,
                        i = e.selectedMonth;
                    0 === e.selectedMonth ? (i = e.name.months.full[e.settings.lang].length, a = e.selectedYear - 1) : e.selectedMonth < 10 && (i = "0".concat(e.selectedMonth));
                    for (var r = 0; r < n; r++) {
                        var d = document.createElement("span");
                        t += 1;
                        var c = "".concat(a, "-").concat(i, "-").concat(t),
                            o = new Date(e.selectedYear, e.selectedMonth, t - 1).getMonth() - 1,
                            h = new Date(e.selectedYear, o, t).getDay();
                        d.className = "vanilla-calendar-day vanilla-calendar-day_prev", d.innerText = "".concat(t), d.dataset.calendarDay = c, s(d, h, c), l.append(d)
                    }
                }(),
                function() {
                    for (var t = e.selectedYear, n = e.selectedMonth < 9 ? "0".concat(e.selectedMonth + 1) : e.selectedMonth + 1, i = 1; i <= a; i++) {
                        var r = document.createElement("span"),
                            d = i < 10 ? "0".concat(i) : i,
                            c = "".concat(t, "-").concat(n, "-").concat(d),
                            o = new Date(e.selectedYear, e.selectedMonth, d).getDay();
                        r.className = "vanilla-calendar-day", r.innerText = "".concat(i), r.dataset.calendarDay = c, s(r, o, c), l.append(r)
                    }
                }(),
                function() {
                    var t = n + a,
                        i = Math.ceil(t / e.name.week[e.settings.lang].length),
                        r = e.name.week[e.settings.lang].length * i - t,
                        d = e.selectedYear,
                        c = e.selectedMonth + 2;
                    e.selectedMonth + 1 === e.name.months.full[e.settings.lang].length ? (c = "01", d = e.selectedYear + 1) : e.selectedMonth + 2 < 10 && (c = "0".concat(e.selectedMonth + 2));
                    for (var o = 1; o <= r; o++) {
                        var h = document.createElement("span"),
                            v = o < 10 ? "0".concat(o) : o,
                            u = "".concat(d, "-").concat(c, "-").concat(v),
                            y = new Date(e.selectedYear, e.selectedMonth, o).getMonth() + 1,
                            g = new Date(e.selectedYear, y, o).getDay();
                        h.className = "vanilla-calendar-day vanilla-calendar-day_next", h.innerText = "".concat(o), h.dataset.calendarDay = u, s(h, g, u), l.append(h)
                    }
                }()
            }
        }, {
            key: "changeMonth",
            value: function(e) {
                var t = this.name.months.full[this.settings.lang].length - 1;
                e.closest(".vanilla-calendar-arrow_prev") ? 0 !== this.selectedMonth ? this.selectedMonth -= 1 : this.settings.selection.year && (this.selectedYear -= 1, this.selectedMonth = t) : e.closest(".vanilla-calendar-arrow_next") && (this.selectedMonth !== t ? this.selectedMonth += 1 : this.settings.selection.year && (this.selectedYear += 1, this.selectedMonth = 0)), this.settings.selected.month = this.selectedMonth, this.controlArrows(), this.writeYear(), this.writeMonth(), this.createDays()
            }
        }, {
            key: "createYears",
            value: function() {
                this.currentType = "year", this.createDOM(), this.controlArrows(), this.writeYear(), this.writeMonth();
                var e = this.HTMLElement.querySelector(".vanilla-calendar-years");
                this.settings.selection.year && e.classList.add("vanilla-calendar-years_selecting");
                for (var t = this.viewYear - 7; t < this.viewYear + 8; t++) {
                    var a = t,
                        n = document.createElement("span");
                    n.className = "vanilla-calendar-years__year", a === this.selectedYear && n.classList.add("vanilla-calendar-years__year_selected"), a < this.dateMin.getFullYear() && n.classList.add("vanilla-calendar-years__year_disabled"), a > this.dateMax.getFullYear() && n.classList.add("vanilla-calendar-years__year_disabled"), n.dataset.calendarYear = a, n.innerText = "".concat(a), e.append(n)
                }
            }
        }, {
            key: "createMonths",
            value: function() {
                this.currentType = "month", this.createDOM(), this.writeYear(), this.writeMonth();
                var e = this.HTMLElement.querySelector(".vanilla-calendar-months");
                this.settings.selection.month && e.classList.add("vanilla-calendar-months_selecting");
                for (var t = this.name.months.reduction[this.settings.lang], a = 0; a < t.length; a++) {
                    var n = t[a],
                        l = document.createElement("span");
                    l.className = "vanilla-calendar-months__month", a === this.selectedMonth && l.classList.add("vanilla-calendar-months__month_selected"), a < this.dateMin.getMonth() && this.selectedYear === this.dateMin.getFullYear() && l.classList.add("vanilla-calendar-months__month_disabled"), a > this.dateMax.getMonth() && this.selectedYear === this.dateMax.getFullYear() && l.classList.add("vanilla-calendar-months__month_disabled"), l.dataset.calendarMonth = a, l.innerText = "".concat(n), e.append(l)
                }
            }
        }, {
            key: "update",
            value: function() {
                this.setVariablesDates(), this.createDOM(), this.controlArrows(), this.writeYear(), this.writeMonth(), "default" === this.currentType ? (this.createWeek(), this.createDays()) : "month" === this.currentType ? this.createMonths() : "year" === this.currentType && this.createYears()
            }
        }, {
            key: "click",
            value: function() {
                var e = this;
                this.HTMLElement.addEventListener("click", (function(t) {
                    var a = t.target.closest(".vanilla-calendar-arrow"),
                        n = t.target.closest(".vanilla-calendar-arrow_prev"),
                        l = t.target.closest(".vanilla-calendar-arrow_next"),
                        s = t.target.closest(".vanilla-calendar-day"),
                        i = t.target.closest(".vanilla-calendar-day_prev"),
                        r = t.target.closest(".vanilla-calendar-day_next"),
                        d = t.target.closest(".vanilla-calendar-year"),
                        c = t.target.closest(".vanilla-calendar-years__year"),
                        o = t.target.closest(".vanilla-calendar-month"),
                        h = t.target.closest(".vanilla-calendar-months__month");
                    ! function() {
                        if (["single", "multiple", "multiple-ranged"].includes(e.settings.selection.day) && s) {
                            if (!i && !r) {
                                switch (e.settings.selection.day) {
                                    case "single":
                                        s.classList.contains("vanilla-calendar-day_selected") ? e.selectedDates.splice(e.selectedDates.indexOf(s.dataset.calendarDay), 1) : (e.selectedDates = [], e.selectedDates.push(s.dataset.calendarDay));
                                        break;
                                    case "multiple":
                                        s.classList.contains("vanilla-calendar-day_selected") ? e.selectedDates.splice(e.selectedDates.indexOf(s.dataset.calendarDay), 1) : e.selectedDates.push(s.dataset.calendarDay);
                                        break;
                                    case "multiple-ranged":
                                        ! function() {
                                            if (e.selectedDates.length > 1 && (e.selectedDates = []), e.selectedDates.push(s.dataset.calendarDay), e.selectedDates[1]) {
                                                var t = new Date(e.selectedDates[0]),
                                                    a = new Date(e.selectedDates[1]),
                                                    n = function(t) {
                                                        var a = new Date(t).getFullYear(),
                                                            n = new Date(t).getMonth() + 1;
                                                        n = n < 10 ? "0".concat(n) : n;
                                                        var l = new Date(t).getDate();
                                                        l = l < 10 ? "0".concat(l) : l;
                                                        var s = "".concat(a, "-").concat(n, "-").concat(l);
                                                        e.settings.range.disabled.length > 0 && e.settings.range.disabled.includes(s) || e.selectedDates.push(s)
                                                    };
                                                if (e.selectedDates = [], a > t)
                                                    for (var l = t; l <= a; l.setDate(l.getDate() + 1)) n(l);
                                                else
                                                    for (var i = t; i >= a; i.setDate(i.getDate() - 1)) n(i)
                                            }
                                        }()
                                }
                                e.actions.clickDay && e.actions.clickDay(t), e.settings.selected.dates = e.selectedDates, e.createDays()
                            }
                        } else a && "year" !== e.currentType && "month" !== e.currentType && e.changeMonth(t.target)
                    }(),
                    function() {
                        if (e.settings.selection.year)
                            if (a && "year" === e.currentType) l ? e.viewYear += 15 : n && (e.viewYear -= 15), e.createYears();
                            else if ("year" !== e.currentType && d) e.createYears();
                        else if ("year" === e.currentType && d) e.currentType = e.type, e.update();
                        else if (c) {
                            var s = Number(c.dataset.calendarYear);
                            e.currentType = e.type, e.selectedMonth < e.dateMin.getMonth() && s === e.dateMin.getFullYear() && (e.settings.selected.month = e.dateMin.getMonth()), e.selectedMonth > e.dateMax.getMonth() && s === e.dateMax.getFullYear() && (e.settings.selected.month = e.dateMax.getMonth()), e.settings.selected.year = s, e.actions.clickYear && e.actions.clickYear(t), e.update()
                        }
                    }(),
                    function() {
                        if (e.settings.selection.month)
                            if ("month" !== e.currentType && o) e.createMonths();
                            else if ("month" === e.currentType && o) e.currentType = e.type, e.update();
                        else if (h) {
                            var a = Number(h.dataset.calendarMonth);
                            e.currentType = e.type, e.settings.selected.month = a, e.actions.clickMonth && e.actions.clickMonth(t), e.update()
                        }
                    }()
                }))
            }
        }, {
            key: "init",
            value: function() {
                this.update(), this.click()
            }
        }]) && t(a.prototype, n), Object.defineProperty(a, "prototype", {
            writable: !1
        }), e
    }();
    return window.VanillaCalendar = a, e
})()));